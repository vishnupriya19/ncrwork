#include<stdio.h>	
#include "E:\visual studio\priya\ncrwork\WindowInternal\MyStatic\mystatic.h"
int main()
{
	double a = 50.4, b = 11.2;
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::Add(a, b));
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::Subtract(a, b));
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::Multiply(a, b));
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::Division(a, b));
}