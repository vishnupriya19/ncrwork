#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;
class Stack
{
	int top;
	int *s;
	int SIZE;
public:
	Stack();
	void getSize(int);
	void push(int);
	int pop();
	int peek();
	bool isFull();
	bool isEmpty();
	void display();
	~Stack();
};
Stack::Stack()
{
	top = -1;
	s = NULL;
	SIZE = 0;
}
void Stack::getSize(int n)
{
	s = new int[n];
	SIZE = n;
}
void Stack::push(int ele)
{
	if (!isFull())
		s[++top] = ele;
	else
		cout << "Stack Full" << "\n";
}
int Stack::pop()
{
	int x = -999;
	if (!isEmpty())
		x = s[top--];
	return x;
}
int Stack::peek()
{
	int x = -999;
	if (!isEmpty())
		x = s[top];
	return x;
}
bool Stack::isFull()
{
	return (top == (SIZE - 1));
}
bool Stack::isEmpty()
{
	return (top == -1);
}
void Stack::display()
{
	int i;
	for (i = 0; i <= top; i++)
		cout << s[i] << " ";
	cout << "\n";
}
Stack::~Stack()
{
	if (s != NULL)
		free(s);
}
int main()
{
	char str[50]; Stack sta;
	int i,a,b;
	cout << "enter postfix expression\n";
	cin >> str;
	sta.getSize(strlen(str));
	for (i = 0; str[i] != '\0'; i++)
	{
		if (isalnum(str[i]))
			sta.push(str[i] - 48);
		else
		{
			a = sta.pop();
			b = sta.pop();
			if (str[i] == '+')
				sta.push(b + a);
			else if (str[i] == '-')
				sta.push(b - a);
			else if (str[i] == '*')
				sta.push(b * a);
			else
				sta.push(b / a);
		}
	}
	cout << sta.peek();

	return 0;
}