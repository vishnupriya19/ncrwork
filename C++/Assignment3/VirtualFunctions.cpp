#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Shape
{
	char *color;
public:
	Shape()
	{
		color = NULL;
	}
	Shape(char *s)
	{
		color = new char[strlen(s)];
		strcpy(color, s);
	}
	void getColor()
	{
		char s[25];
		cout << "enter color\n";
		cin >> s;
		color = new char[strlen(s)];
		strcpy(color, s);
	}
	void displayColor()
	{
		cout << "Color = " << color << endl;
	}
	virtual void displayArea()
	{
		cout << "In shape\n";
	}
	~Shape()
	{
		if (color != NULL)
			delete color;
	}
};
class Triangle :public Shape
{
	int base, height;
public:
	Triangle()
	{
		base = height = 0;
	}
	Triangle(int var)
	{
		base = height = var;
	}
	Triangle(int b, int h)
	{
		base = b;
		height = h;
	}
	void displayArea()
	{
		cout << "Area of triangle = " << 0.5*base*height << endl;
	}
};
class Square :public Shape
{
	int side;
public:
	Square(int s)
	{
		side = s;
	}
	void displayArea()
	{
		cout << "Area of square = " << side * side << endl;
	}
};
class Rectangle :public Shape
{
	int length, breadth;
public:
	Rectangle()
	{
		length = breadth = 0;
	}
	Rectangle(int var)
	{
		length = breadth = var;
	}
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}
	void displayArea()
	{
		cout << "Area of Rectangle = " << length * breadth << endl;
	}
};
int main()
{
	Triangle triangle(10, 5);
	Square square(4);
	Rectangle rectangle(10, 5);
	Shape *shape[3] = { &triangle,&square,&rectangle };
	//shape[0] = &triangle;
	for (int i = 0; i < 3; i++)
		shape[i]->displayArea();
	return 0;
}