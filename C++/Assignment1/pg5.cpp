#include<stdio.h>
#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
	float meter;
	float centi;
public:
	Distance1()
	{
		meter = centi = 0;
	}
	Distance1(float d)
	{
		meter = centi = d;
	}
	Distance1(float d1, float d2)
	{
		meter = d1;
		centi = d2;
	}
	friend void CalculateDist(Distance1 d1, Distance2 d2);
};
class Distance2
{
	float feet;
	float inch;
public:
	Distance2()
	{
		feet = inch = 0;
	}
	Distance2(float d)
	{
		feet = inch = d;
	}
	Distance2(float d1,float d2)
	{
		feet = d1;
		inch = d2;
	}
	friend void CalculateDist(Distance1 d1, Distance2 d2);
};
void CalculateDist(Distance1 d1, Distance2 d2)
{
	int c;
	float tot;
	printf("enter 1.meters 2.feet\n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:tot = d1.meter + 0.01f*d1.centi + d2.feet * 0.3 + d2.inch * 0.3 * 0.0245;
		break;
	case 2:tot = 3.28 * d1.meter + 0.01f * 3.28 * d1.centi + d2.feet + 0.08 * d2.inch;
		break;
	}
	cout << "Total = " << tot;
}
int main()
{
	Distance1 d1(2, 3);
	Distance2 d2(3, 4);
	CalculateDist(d1, d2);
	return 0;
}
