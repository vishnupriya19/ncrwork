#include<iostream>
using namespace std;
class Base
{
	int x;
public:
	int y;
	Base()
	{
		x = 10;
		y = 11;
		z = 12;
	}
protected:
	int z;
};
class privI :private Base
{
	//y and z becomes private and x can't be accessed inherited
public:
	void display()
	{
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
};
class protI :protected Base
{
public:
	//y and z becomes protected
	void display()
	{
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
};
int main()
{
	Base obj;
	privI pri;
	protI pro;
	pri.display();
	pro.display();
}