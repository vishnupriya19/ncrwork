#include<stdio.h>
#include<iostream>
using namespace std;
inline int add(int a, int b)
{
	return a + b;
}
inline int sub(int a, int b)
{
	return a - b;
}
inline int mul(int a, int b)
{
	return a * b;
}
inline float divi(int a, int b)
{
	return a / b;
}
inline int mod(int a, int b)
{
	return a % b;
}
int main()
{
	int a = 10, b = 5;
	cout << "add = " << add(a, b) << "\n";
	cout << "sub = " << sub(a, b) << "\n";
	cout << "mul = "<< mul(a, b) << "\n";
	cout << "div = " << divi(a, b) << "\n";
	cout << "mod = " << mod(a, b) << "\n";
	return 0;
}