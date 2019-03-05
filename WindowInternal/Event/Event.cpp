#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
HANDLE hEvent;
DWORD WINAPI COUNT_WORDS(LPVOID lparam)
{
	WaitForSingleObject(hEvent,INFINITE);
	printf("Counting words\n");
	return 0;
}
DWORD WINAPI CHECK_SPELLING(LPVOID lparam)
{
	WaitForSingleObject(hEvent, INFINITE);
	printf("Spelling check\n");
	return 0;
}
DWORD WINAPI CHECK_GRAMMAR(LPVOID lparam)
{
	WaitForSingleObject(hEvent, INFINITE);
	printf("Grammar check\n");
	return 0;
}
int main()
{
	DWORD thId1, thId2, thId3;
	HANDLE hThread1, hThread2, hThread3;
	hEvent = CreateEvent(NULL, TRUE, FALSE, TEXT("namedobject"));
	hThread1 = CreateThread(NULL,//SECURITY_ATTRIBUTES
		0,//dwStackSize
		COUNT_WORDS,//Pointer to function to be executed by thread
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
		CHECK_SPELLING,
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
	hThread3 = CreateThread(NULL,
		0,
		CHECK_GRAMMAR,
		NULL,
		0,
		&thId3
	);
	if (hThread3 == NULL)
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	printf("File opened\n");
	SetEvent(hEvent);
	getchar();
	return 0;
}