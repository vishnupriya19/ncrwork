#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int _tmain(int argc,TCHAR *argv[])
{
	HANDLE hFile;
	TCHAR buff[BUFFERSIZE];
	//_tprintf(_T("%S"), argv[1]);
	//return 0;
	//LPCWSTR fileName = L"welcome.txt";
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File open error : %d\n"), GetLastError());
		getchar();
		return -1;
	}
	_tprintf(_T("File openend successfully : %s\n"), argv[1]);
	DWORD nbr;
	ZeroMemory(buff, BUFFERSIZE);
	BOOL ret = ReadFile(hFile, buff,BUFFERSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Cant read file Error %d\n"), GetLastError());
		getchar();
		return -1;
	}
	CloseHandle(hFile);
	_tprintf(_T("Text from %s to %S"), argv[1], buff);
	getchar();
	return 0;
}