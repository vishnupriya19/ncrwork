
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
//#include<iostream>
//using namespace std;
#define BUFFERSIZE 100

int _tmain(int argc, TCHAR *argv[])
{
	HANDLE hFile;
	TCHAR buff[BUFFERSIZE];
	//_tprintf(_T("%S"), argv[1]);
	//return 0;
	LPCTSTR fileName = TEXT("welcome.txt");

	hFile = CreateFile(fileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File open error : %d\n"), GetLastError());
		getchar();
		return 0;
	}
	_tprintf(_T("File openend successfully : %s\n"), fileName);
	DWORD nbr;
	while (1)
	{
		ZeroMemory(buff, sizeof(buff));
		BOOL ret = ReadFile(hFile, buff, BUFFERSIZE, &nbr, NULL);
		if (ret == FALSE)
		{
			_tprintf(_T("Cant read file Error %d\n"), GetLastError());
			getchar();
			return -1;
		}		
		else if (ret == TRUE && nbr==0) // EOF
			break;
		
		_tprintf(_T("%LS"), buff);
	}
	CloseHandle(hFile);
	return 0;
}