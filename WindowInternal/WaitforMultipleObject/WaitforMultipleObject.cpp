#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
DWORD WINAPI thread_fun1(LPVOID lparam)
{
	Sleep(5000);
	return 0;
}
DWORD WINAPI thread_fun2(LPVOID lparam)
{
	Sleep(2000);
	return 0;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hThread1, hThread2;
	HANDLE arr[2];
		hThread1 = CreateThread(NULL,//SECURITY_ATTRIBUTES
			0,//dwStackSize
			thread_fun1,//Pointer to function to be executed by thread
			NULL,//Pointer to the variable to be passed to thread
			0,//Creation flag controls the creation of thread
			&thId1//pointer to variable that receives thread identifier
		);
		if (hThread1 == NULL)
		{
			printf("Unable to create thread %d\n", GetLastError());
			getchar();
			return 0;
		}
		hThread2 = CreateThread(NULL,
			0,
			thread_fun2,
			NULL,
			0,
			&thId2
		);
		if (hThread2 == NULL)
		{
			printf("Unable to create thread %d\n", GetLastError());
			getchar();
			return 0;
		}
		arr[0] = hThread1;
		arr[1] = hThread2;
		DWORD dwRet = WaitForMultipleObjects(2,//no of object handles 
			arr,//array which contains object handle
			TRUE,//wheather to wait for all objects or not
			1000//dwMilliSeconds
		);
		switch (dwRet)
		{
		case WAIT_FAILED:printf("wait failed\n");
			break;
		case WAIT_TIMEOUT:printf("Wait Timeout\n");
			break;
		case WAIT_OBJECT_0 + 0:printf("Thread 1 terminated\n");
			break;
		case WAIT_OBJECT_0 + 1:printf("Thread 2 terminated\n");
			break;
		}
		
	//WaitForSingleObject(hThread, 1000);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	getchar();
	return 0;
}