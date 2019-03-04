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
	hThread = CreateThread(NULL, //SECURITY_ATTRIBUTES
		0,	//dwStacksize
		thread_fun,//Pointer to function to be executed by thread
		NULL,//Pointer to the variable to be passed to thread
		0,//Creation flag controls the creation of thread
		&thId//pointer to variable that receives thread identifier
	);
	if (hThread == NULL) //failure
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	//WaitForSingleObject(hThread, 1000);
	printf("Thread creation successfull\n");
	CloseHandle(hThread);
	getchar();
	return 0;
}