#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 150
int main(int argc, TCHAR *argv[])
{
	HANDLE hFile;
	TCHAR buff[BUFFERSIZE]=TEXT("VNR Vignana Jyothi Institute Of Engineering And Technology");
	//_tprintf(_T("%S"), argv[1]);
	//return 0;
	LPCWSTR fileName = L"newFile.txt";
	hFile = CreateFile(fileName, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File create error : %d\n"), GetLastError());
		getchar();
		return -1;
	}
	_tprintf(_T("File created successfully : %s\n"), fileName);
	DWORD nbr;
	BOOL ret = WriteFile(hFile, buff, BUFFERSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Cant read file Error %d\n"), GetLastError());
		getchar();
		return -1;
	}
	CloseHandle(hFile);
	_tprintf(_T("Written Text to %s"), fileName);
	getchar();
	return 0;
}