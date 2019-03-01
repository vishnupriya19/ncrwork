#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int main(int argc, CHAR* argv[])
{
	cout << "Hello ";
	DWORD nbr;
	TCHAR buff[BUFFERSIZE];
	ZeroMemory(buff, sizeof(buff));
	int i = atoi(argv[0]);
	HANDLE hFile=(HANDLE)i;
	//_tprintf(_T("Handle value in HI = %S\n"), argv[0]);
	printf("Handle value in HI = %d\n", hFile);
	BOOL ret = ReadFile(hFile, buff, BUFFERSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Cant read file Error %d\n"), GetLastError());
		getchar();
		return -1;
	}
	_tprintf(_T("Text in %S"),buff);
	CloseHandle(hFile);
	getchar();
	return 0;
}