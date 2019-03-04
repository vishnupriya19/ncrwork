
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

	hFile = CreateFile(fileName,//name of the file to be opened
					GENERIC_READ,//desired access
					0, //shared mode
					NULL,//SecurityAttribues
					OPEN_EXISTING,//action to take on a file or device that exists or don't exist
					FILE_ATTRIBUTE_NORMAL, //file attribues and flags
					NULL//handle to GENERIC-READ file that supplies attribues to file
					);
	if (hFile == INVALID_HANDLE_VALUE) //failure
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