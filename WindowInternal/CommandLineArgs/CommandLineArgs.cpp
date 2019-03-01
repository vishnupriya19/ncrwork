#include<stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	LPWSTR *szArglist;
	int nArgs;
	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (NULL == szArglist)
	{
		cout << "CommandLineToArgvW failed\n";
		return 0;
	}
	for (int i = 0; i < nArgs; i++)
	{
		cout << i << " "; 
		wcout << szArglist[i] << endl;
	}
	return 0;
}