#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int main(int argc, CHAR* argv[])
{
	//cout << "Hello ";
	DWORD nbr;
	TCHAR buff[BUFFERSIZE];
	ZeroMemory(buff, BUFFERSIZE);
	int i = atoi(argv[0]);
	HANDLE hFile = (HANDLE)i;
	_tprintf(_T("Handle value in HI = %s\n"), argv[0]);
	printf("Handle value in HI = %d\n", hFile);
	//HANDLE hFile1;
	//CloseHandle(hFile);
	CloseHandle(hFile);
	getchar();
	return 0;
}