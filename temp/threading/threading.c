/*
多线程输出示例 
*/

#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID n)
{
	int i;
	for(i=0;i<10;i++)
		printf("%d%d%d%d%d\n",n,n,n,n,n);
	int j;
	for(j=0;j<10000000;j++);
	return 0;
}

int main()
{
	HANDLE hThrd;
	DWORD threadId;
	int i;

	for(i=0;i<5;i++)
	{
		hThrd=CreateThread(NULL,0,ThreadFunc,(LPVOID)i,0,&threadId);
		if(hThrd)
		{
			printf("Thread launched %d\n",i);
			CloseHandle(hThrd);
		}
	}
	Sleep(2000);
	getchar();
	return EXIT_SUCCESS;
}
