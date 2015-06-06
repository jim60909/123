#include <stdio.h>
#include <signal.h>

//ID:B0342301 
//Date:2015/06/6 
//Detail:Lab4 Ex1 in windows

void Catch_Int(int);

int main()
{
	//設定 signal(INT , ctrl-c) 接收
	signal(SIGINT,Catch_Int);
	
	//讓主程序進入睡眠，避免結束 
	sleep(9999);
	return 0;
}

void Catch_Int(int signalInput)
{
	//重新設定 signal(INT , ctrl-c) 接收
	signal(SIGINT,Catch_Int);
	printf("HEY GIRL\n");
	fflush(stdout);
}
