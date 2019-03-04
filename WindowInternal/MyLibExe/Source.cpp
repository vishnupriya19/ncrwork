#include<stdio.h>
#include "MyLib.h"
int main()
{
	int a = 5, b = 10;
	printf("Result of %d + %d = %d\n",a,b,add(a,b));
	printf("Result of %d - %d = %d\n", a, b, sub(a, b));
	printf("Result of %d * %d = %d\n", a, b, mul(a, b));
	printf("Result of %d / %d = %d\n", a, b, division(a, b));
	return 0;
}