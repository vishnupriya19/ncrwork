#include<stdio.h>
#include<iostream>
using namespace std;
class Size
{
	int i;
public:
	Size()
	{
		cout << "Construct called ";
	}
	Size(int i)
	{
		this->i = i;
		cout << "Constructor called " << i << endl;
	}
	~Size()
	{
		cout << "Destructor called " << i << endl;
	}
};
int main()
{
	Size s1(1), s2(2);
	cout << sizeof(s1) << endl << sizeof(s2) << endl;
	return 0;
}