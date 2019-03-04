#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<iostream>
using namespace std;
int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	//SECURITY_ATTRIBUTES sa;
	//HANDLE hProcess;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	LPWSTR lp=NULL;
	lp = new WCHAR[100];
	//cout << _countof(L"notepad");
	wcscpy_s(lp,_countof(L"notepad"), L"notepad");
	//wcout << lp << endl;
	if (!CreateProcess(
		NULL,//Application name
		lp,//Command Line
		NULL,//Process Atrributes
		NULL,//Thread Attributes
		FALSE,//Handle inheritance
		0,//Priority class
		NULL,//Pointer to environment block of new process
		NULL,//Full path to current directory of process
		&si,//Pointer to STARTUPINFO structure
		&pi//POinter to PROCESSINFORMATION structure
	))
	{
		printf("Create process error %d\n", GetLastError());
		getchar();
		return 0;
	}
	printf("Handle of process %ld\n", pi.hProcess);
	printf(" Process id process %ld\n", pi.dwProcessId);
	printf("Handle of thread %ld\n", pi.hThread);
	printf(" Process id thread %ld\n", pi.dwThreadId);
	cout << "\n";

	delete lp;
	lp = new WCHAR[100];
	//cout << wcslen(L"notepad");
	wcscpy_s(lp, _countof(L"calc.exe"), L"calc.exe");
	//wcout << lp << endl;
	if (!CreateProcess(
		NULL,
		lp,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		printf("Create process error %d\n", GetLastError());
		getchar();
		return 0;
	}
	printf("Id of current process %ld\n", GetCurrentProcessId());
	printf("Id of current thread %ld\n", GetCurrentThreadId());
	printf("Id of process %ld\n", GetProcessId(pi.hProcess));
	printf("Id of thread %ld\n", GetThreadId(pi.hThread));
	printf("Process Id of Thread %ld", GetProcessIdOfThread(pi.hThread));

	delete lp;
	return 0;
}
