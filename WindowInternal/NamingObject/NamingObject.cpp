#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE g_Event = CreateEvent(NULL, FALSE, FALSE, TEXT("namedobject"));
	CloseHandle(g_Event);
	getchar();
	return 0;
}