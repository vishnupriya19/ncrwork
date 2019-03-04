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
	BOOL bRes;

	cout << "enter wchar array\n";
	wcin >> wArray;
	cout << "enter char array\n";
	cin >> cArray;

	//Checking if the given array is unicode or not
	bRes = IsTextUnicode(wArray,//pointer to input buffer
						wcslen(wArray),//size of input buffer in bytes
						NULL//points to tests to be applied on the input buffer
						);
	if (bRes == 0)
		printf("%S is not unicode text\n", wArray);
	else
		printf("%S is unicode text\n", wArray);
	bRes = IsTextUnicode(cArray, strlen(cArray), NULL);
	if (bRes == 0)
		printf("%s is not unicode text\n", cArray);
	else
		printf("%s is unicode text\n", cArray);

	//Converting given MultiByte to WideCharacter Array
	int req = MultiByteToWideChar(CP_UTF8, //code page
								  0,	//conversion type
								  cArray, //pointer to multibyte array
								  -1,   // sizeof multibyte array
								  NULL,	//pointer to widechar array that receives ouput
								  0); //sizeof widechar array
	printf("Required bytes = %d\n", req);
	if (req == 0)
		cout << "Error occured " << GetLastError();
	WCHAR *wArray2 = new WCHAR[req];
	bRes = MultiByteToWideChar(CP_UTF8, 0, cArray, strlen(cArray), wArray, req);
	if (bRes == 0)
		cout << "MultiByte is not converted to WideCharacter\n";
	else
		cout << "MultiByte is converted to WideCharacter\n";

	//converting WideCharacter to MultiByte 
	req = WideCharToMultiByte(CP_UTF8,//code page
								0,//conversion type
								wArray,//pointer to widechar array
								-1,//sizeof widechar array
								NULL,//pointer to multibyte array that receives the output
								0, //sizeof multibyte array
								NULL,//default character
								NULL// if the function has used default character or not
								);
	if (req == 0)
		cout << "Error occured " << GetLastError();
	CHAR *cArray2 = new CHAR[req];
	printf("Required bytes = %d\n", req);
	bRes = WideCharToMultiByte(CP_UTF8, 0, wArray, -1, cArray2, req, NULL, NULL);
	if (bRes == 0)
		cout << "WideCharacter is not converted to MultiByte\n";
	else
		cout << "WideCharacter is converted to MultiByte\n";

	return 0;
}
