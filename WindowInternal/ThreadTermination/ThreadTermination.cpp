#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf(" i = (%d)\n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD thId;
	HANDLE hThread;
	hThread = CreateThread(NULL,//SECURITY_ATTRIBUTES
		0,//dwStackSize
		thread_fun,//Pointer to function to be executed by thread
		NULL,//Pointer to the variable to be passed to thread
		0,//Creation flag controls the creation of thread
		&thId//pointer to variable that receives thread identifier
	);
	if (hThread == NULL)
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	WaitForSingleObject(hThread, 6000);
	DWORD dwExitCode=1;
	BOOL getCode = GetExitCodeThread(hThread,&dwExitCode);
	printf("Exit code = %d\n", dwExitCode);
	if (getCode != 0)
		printf("Exit code retreived successfully\n");
	else
		printf("Exit code not retreived");
	BOOL term=TerminateThread(hThread, dwExitCode);
	if (term == 0)
		printf("thread not terminated\n");
	else
		printf("thread terminated\n");
	CloseHandle(hThread);
	getchar();
	return 0;
}