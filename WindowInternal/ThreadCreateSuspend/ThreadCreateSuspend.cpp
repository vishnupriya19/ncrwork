#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf(" i = (%d)\n", i);
		//Sleep(1000);
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
	Sleep(5000);
	ResumeThread(hThread);
	if (hThread == NULL)
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	//WaitForSingleObject(hThread, 1000);
	CloseHandle(hThread);
	getchar();
	return 0;
}