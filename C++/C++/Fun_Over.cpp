#include<stdio.h>
#include<iostream>
using namespace std;
void add(double d1, double d2)
{
	double res = d1 + d2;
	cout << res;
}
void add(short d1, short d2)
{
	double res = d1 + d2;
	cout << res;
}
void add(long d1, long d2)
{
	double res = d1 + d2;
	cout << res;
}
int main()
{
	add(2.3f, 5.6f);
	return 0;
}