#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class String
{
public:
	char *a;
	int len;
	String()
	{
		a = NULL;
		len = 0;
	}
	String(char *s)
	{
		len = strlen(s);
		a = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(a, s);
	}
	String operator+(String b)
	{
		String c;
		int len = len + b.len + 2;
		c.a = (char*)malloc(sizeof(char)*len);
		strcat(c.a, a);
		strcat(c.a, b.a);
		//cout << c;
		return c;
	}
	String operator=(String s1)
	{
		len = s1.len;
		if(a==NULL)
		a = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(a, s1.a);
		return (*this);
	}
	char operator[](int i)
	{
		return a[i];
	}
};
int main()
{
	char c;
	String s1("vishnu"), s2("priya"), s3;
	s3 = s1 + s2;
	//cout << s;
	cout << s3.a<<"\n";
	s3 = s1;
	cout << s3.a << "\n";
	c =  s3[3];
	cout << c;
	return 0;
}