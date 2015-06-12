#include <Windows.h>
#include <stdio.h>
#include <unistd.h>

#define Max_Sem 4
#define Thread_Num 8

HANDLE Semaphore;

void ThreadProc(LPVOID);

int Thread_ID[8];

int main( void )
{
    HANDLE Thread[Thread_Num];
    DWORD ThreadID;
    int i;

    Semaphore = CreateSemaphore(NULL,Max_Sem,Max_Sem,NULL);

    if (Semaphore == NULL) 
    {
        printf("CreateSemaphore error: %d\n", GetLastError());
        return 1;
    }

    for( i=0; i < Thread_Num; i++ )
    {
    	*(Thread_ID+i) = i;
        Thread[i] = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE) ThreadProc,Thread_ID+i,0,&ThreadID);

        if(Thread[i] == NULL)
        {
            printf("CreateThread error: %d\n", GetLastError());
            return 1;
        }
    }

    WaitForMultipleObjects(Thread_Num, Thread, TRUE, INFINITE);

    for( i=0; i < Thread_Num; i++ )
        CloseHandle(Thread[i]);

    CloseHandle(Semaphore);

    return 0;
}

void ThreadProc(LPVOID lpParam)
{
	int i;
	int* Param = (int*) lpParam;

    for(i=0;i<2;i++)
    {
		printf("Thread %d is NON critical\n",*Param);
		sleep(5000);
		
        WaitForSingleObject(Semaphore,INFINITE);        
        
        printf("Thread %d entering critical section\n",*Param);
        Sleep(5000);
        printf("Thread %d leaving critical section\n",*Param);
        
        if(!ReleaseSemaphore(Semaphore,1,NULL))
        	printf("ReleaseSemaphore error: %d\n", GetLastError());
    }
    return;
}
