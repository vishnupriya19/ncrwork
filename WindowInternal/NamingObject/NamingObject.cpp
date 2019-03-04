#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE hEvent = CreateEvent(NULL,//Pointer to SECURITY_ATTRIBUTES structure
								FALSE,//Manual Reset
								FALSE,//Initial State
								TEXT("namedobject")//Name of the event
								);
	if (NULL == hEvent)
	{
		printf("Create event function failed\n");
		return 0;
	}
	printf("Create event successfull\n");
	printf("Handle to event = %d", hEvent);
	CloseHandle(hEvent);
	getchar();
	return 0;
}