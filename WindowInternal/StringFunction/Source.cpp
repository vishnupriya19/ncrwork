#include<stdio.h>
#include<Windows.h>
#include<strsafe.h>
#include<tchar.h>
//#include<errno.h>
#include<iostream>
using namespace std;
int main()
{
	WCHAR wArray[25];
	CHAR cArray[25];
	int res;

	cout << "enter wchar array\n";
	wcin >> wArray;
	cout << "enter char array\n";
	cin >> cArray;

	//WideCharacter strcpy function
	WCHAR *wArray3 = new WCHAR[_countof(wArray)];
	int err = wcscpy_s(wArray3, _countof(wArray), wArray);
	if (err != 0)
		cout << L"Error in strcpy " << err;
	else
		wcout << L"Original content " << wArray << endl << L"Copied content " << wArray3 << endl;

	//tchar strcpy function
	TCHAR tArray[25] = TEXT("Window");
	TCHAR tArray2[25];
	err = _tcscpy_s(tArray2, _tcslen(tArray) + 1, tArray);
	if (err != 0)
		cout << L"Error in strcpy " << err;
	else
		wcout << L"Original content " << tArray << endl << L"Copied content " << tArray2 << endl;

	return 0;
}