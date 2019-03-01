#include<stdio.h>
#include<Windows.h>
#include<strsafe.h>
//#include<errno.h>
#include<iostream>
#include<tchar.h>
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

	//Checking if the given array is unicode or not
	res = IsTextUnicode(wArray, wcslen(wArray), NULL);
	if (res == 0)
		printf("%S is not unicode text\n", wArray);
	else
		printf("%S is unicode text\n", wArray);
	res = IsTextUnicode(cArray, strlen(cArray), NULL);
	if (res == 0)
		printf("%s is not unicode text\n", cArray);
	else
		printf("%s is unicode text\n", cArray);

	//Converting given MultiByte to WideCharacter Array
	int req = MultiByteToWideChar(CP_UTF8, 0, cArray, -1, NULL, 0);
	printf("Required bytes = %d\n", req);
	if (req == 0)
		cout << "Error occured " << GetLastError();
	WCHAR *wArray2 = new WCHAR[req];
	res = MultiByteToWideChar(CP_UTF8, 0, cArray, strlen(cArray), wArray, req);
	if (res == 0)
		cout << "MultiByte is not converted to WideCharacter\n";
	else
		cout << "MultiByte is converted to WideCharacter\n";

	//converting WideCharacter to MultiByte 
	req = WideCharToMultiByte(CP_UTF8, 0, wArray, -1, NULL, 0, NULL,NULL);
	if (req == 0)
		cout << "Error occured " << GetLastError();
	CHAR *cArray2 = new CHAR[req];
	printf("Required bytes = %d\n", req);
	res = WideCharToMultiByte(CP_UTF8, 0, wArray, -1, cArray2, req, NULL, NULL);
	if (res == 0)
		cout << "WideCharacter is not converted to MultiByte\n";
	else
		cout << "WideCharacter is converted to MultiByte\n";

	return 0;
}
