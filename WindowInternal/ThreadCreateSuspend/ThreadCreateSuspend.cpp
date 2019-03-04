#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	for (int i = 0; i < 10; i++)
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
	hThread = CreateThread(NULL,//SECURITY_ATTRIBUTES
		0,//dwStackSize
		thread_fun,//Pointer to function to be executed by thread
		NULL,//Pointer to the variable to be passed to thread
		CREATE_SUSPENDED,//Creation flag controls the creation of thread
		&thId); //pointer to variable that receives thread identifier
	
	if (hThread == NULL) //failure
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	//Sleep(5000);
	WaitForSingleObject(hThread, 5000);
	ResumeThread(hThread);
	CloseHandle(hThread);
	getchar();
	return 0;
}