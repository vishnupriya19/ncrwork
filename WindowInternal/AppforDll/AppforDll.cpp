#include<stdio.h>
#include<Windows.h>
#include "MyLib.h"

typedef int(*add1)(int, int);
typedef int(*sub1)(int, int);
typedef int(*mul1)(int, int);
typedef int(*division1)(int, int);

typedef int(*MYPROC)(int, int);

int main()
{
	HMODULE hdl;
	int sum, sub, mul, div;
	MYPROC ADD, SUB, MUL, DIV;
	hdl = LoadLibraryEx(
		TEXT("E:\\visual studio\\priya\\ncrwork\\WindowInternal\\Debug\\MyLib.dll"),
		NULL,
		NULL
	);
	if (hdl == NULL)
	{
		printf("LoadLibraryEx failed with error code %d\n", GetLastError());
		getchar();
		return 0;
	}
	ADD = (MYPROC)GetProcAddress(hdl, (LPCSTR)"add");
	if (ADD == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	sum = ADD(20, 10);
	printf("Sum of 20 and 10 = %d\n", sum);

	SUB = (MYPROC)GetProcAddress(hdl, (LPCSTR)"sub");
	if (SUB == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	sub = SUB(20, 10);
	printf("Difference of 20 and 10 = %d\n", sub);

	MUL = (MYPROC)GetProcAddress(hdl, (LPCSTR)"mul");
	if (MUL == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	mul = MUL(20, 10);
	printf("Multiplication of 20 and 10 = %d\n", mul);

	DIV = (MYPROC)GetProcAddress(hdl, (LPCSTR)"division");
	if (DIV == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	div = DIV(20, 10);
	printf("Division of 20 and 10 = %d\n", div);
	return 0;
}