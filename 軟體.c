#include <stdio.h>
#include <signal.h>

//ID:B0342301 
//Date:2015/06/6 
//Detail:Lab4 Ex1 in windows

void Catch_Int(int);

int main()
{
	//�]�w signal(INT , ctrl-c) ����
	signal(SIGINT,Catch_Int);
	
	//���D�{�Ƕi�J�ίv�A�קK���� 
	sleep(9999);
	return 0;
}

void Catch_Int(int signalInput)
{
	//���s�]�w signal(INT , ctrl-c) ����
	signal(SIGINT,Catch_Int);
	printf("HEY GIRL\n");
	fflush(stdout);
}
