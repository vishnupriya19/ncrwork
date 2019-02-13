#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void swap_value(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap_reference(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
int main()
{
	int a,b,c;
	printf("enter a and b\n");
	scanf("%d%d", &a, &b);
	printf("enter your choice 1.swap by value 2.swap by reference\n");
	scanf("%d", &c);
	printf("Before swap a = %d,b= %d\n", a, b);
	switch (c)
	{
	case 1:swap_value(a, b);
		break;
	case 2:swap_reference(a, b);
		break;
	}
	printf("After swap a = %d,b= %d", a, b);
	return 0;
}