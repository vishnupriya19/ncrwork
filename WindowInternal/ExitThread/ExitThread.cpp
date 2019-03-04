#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
DWORD dwExitCode;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf(" i = (%d)\n", i);
		//Sleep(1000);
		if (i == 4)
		{
			ExitThread(dwExitCode);
		}
	}
	return 0;
}
int main()
{
	DWORD thId;
	HANDLE hThread;
	hThread = CreateThread(NULL,
		0,
		thread_fun,
		NULL,
		CREATE_SUSPENDED,
		&thId
	);
	if (hThread == NULL)
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	
	//DWORD dwExitCode = 1;
	//TerminateThread(hThread, dwExitCode);

	BOOL getCode = GetExitCodeThread(hThread, &dwExitCode);
	printf("Exit code = %d\n", dwExitCode);
	if (getCode != 0)
		printf("Exit code retreived successfully\n");
	else
		printf("Exit code not retreived");
	ResumeThread(hThread);
	WaitForSingleObject(hThread, 6000);
	CloseHandle(hThread);
	printf("Thread exited successfully\n");
	getchar();
	return 0;
}