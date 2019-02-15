#include<stdio.h>
#include<iostream>
using namespace std;
class Polar
{
	int angle;
	int radius;
public:
	static int count;
	Polar()
	{
		count++;
		angle = radius = 0;
	}
	Polar(int a)
	{
		count++;
		angle = radius = a;
	}
	Polar(int a, int r)
	{
		count++;
		angle = a;
		radius = r;
	}
	~Polar()
	{
		count--;
	}
};
int Polar::count;
int main()
{
	Polar p1(30, 12), p2(21);
	cout << Polar::count;
	return 0;
}