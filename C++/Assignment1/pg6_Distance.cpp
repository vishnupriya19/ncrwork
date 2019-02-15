#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
class Coordinate
{
	int x;
	int y;
public:
	Coordinate()
	{
		x = y = 0;
	}
	Coordinate(int a)
	{
		x = y = a;
	}
	Coordinate(int a, int b)
	{
		x = a; y = b;
	}
	friend void calculateDistance(Coordinate,Coordinate);
};
void calculateDistance(Coordinate c1, Coordinate c2)
{
	float dist;
	dist = sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2));
	cout << dist;
}
int main()
{ 
	Coordinate c1(3, 3), c2(4,4);
	calculateDistance(c1, c2);
	return 0;
}
