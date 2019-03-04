#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
//#include<Wdm.h>
#include<iostream>
using namespace std;
long g_x;
DWORD WINAPI thread_fun1(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}
DWORD WINAPI thread_fun2(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hThread1, hThread2;
	HANDLE arr[2];
	while (1)
	{
		g_x = 0;
		hThread1 = CreateThread(NULL,
			0,
			thread_fun1,
			NULL,
			0,
			&thId1
		);
		if (hThread1 == NULL)
		{
			printf("Unable to create thread %d\n", GetLastError());
			getchar();
			return 0;
		}
		hThread2 = CreateThread(NULL,//SECURITY_ATTRIBUTES
			0,//dwStackSize
			thread_fun2,//Pointer to function to be executed by thread
			NULL,//Pointer to the variable to be passed to thread
			0,//Creation flag controls the creation of thread
			&thId2//pointer to variable that receives thread identifier
		);
		if (hThread2 == NULL)
		{
			printf("Unable to create thread %d\n", GetLastError());
			getchar();
			return 0;
		}
		arr[0] = hThread1;
		arr[1] = hThread2;
		WaitForMultipleObjects(2,//no of object handles 
								arr,//array which contains object handle
								TRUE,//wheather to wait for all objects or not
								INFINITE//dwMilliSeconds
		);
		printf("%d\n", g_x);
		if (g_x == 1)
			break;
	}
	//WaitForSingleObject(hThread, 1000);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	getchar();
	return 0;
}