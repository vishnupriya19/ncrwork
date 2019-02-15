#include<stdio.h>
#include<iostream>
using namespace std;
class Complex
{
	float real;
	float img;
public:
	Complex()
	{
		real = img = 0;
	}
	Complex(double a)
	{
		real = img = a;
	}
	Complex(double a, double b)
	{
		real = a;
		img = b;
	}
	void display()
	{
		printf("Complex Number is\n");
		cout << real << "+" << img << "i" << "\n";
	}
	friend Complex add(Complex, Complex);
	friend Complex mul(Complex, Complex);
};
Complex add(Complex a, Complex b)
{
	Complex c;
	c.real = a.real + b.real;
	c.img = a.img + b.img;
	return c;
}
Complex mul(Complex a, Complex b)
{
	Complex c;
	c.real = (a.real*b.real) - (a.img*b.img);
	c.img = (a.real*b.img) + (a.img*b.real);
	return c;
}
int main()
{
	Complex c1(5), c2(3, 2), c3;
	c3 = add(c1, c2);
	c3.display();
	c3 = mul(c1, c2);
	c3.display();
	return 0;
}