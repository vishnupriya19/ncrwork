#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;
class Stack
{
	int top;
	char *s;
	int SIZE;
public:
	Stack();
	void getSize(int);
	void push(char);
	char pop();
	char peek();
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
	s = new char[n];
	SIZE = n;
}
void Stack::push(char ele)
{
	if (!isFull())
		s[++top] = ele;
	else
		cout << "Stack Full" << "\n";
}
char Stack::pop()
{
	char x = '\0';
	if (!isEmpty())
		x = s[top--];
	return x;
}
char Stack::peek()
{
	char x = '\0';
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
int prec(char a)
{
	if (a == '*' || a == '/')
		return 3;
	else if (a == '+' || a == '-')
		return 2;
	else if (a == '(' || a == '{' || a == '[')
		return 1;
	return 0;
}
int main()
{
	char str[50],op[50];
	int i,j=0; Stack sta;
	cout << "enter infix expression\n";
	cin >> str;
	sta.getSize(strlen(str));
	for (i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i]))
			op[j++] = str[i];
		else if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			sta.push(str[i]);
		else if (str[i] == ')')
		{
			while (sta.peek() != '(')
				op[j++] = sta.pop();
			sta.pop();
		}
		else if (str[i] == ']')
		{
			while (sta.peek() != '[')
				op[j++] = sta.pop();
			sta.pop();
		}
		else if (str[i] == '}')
		{
			while (sta.peek() != '}')
				op[j++] = sta.pop();
			sta.pop();
		}
		else
		{
			while (prec(sta.peek()) >= prec(str[i]))
				op[j++] = sta.pop();
			sta.push(str[i]);
		}

	}
	while (!sta.isEmpty())
		op[j++] = sta.pop();
	op[j] = '\0';
	cout << op;
	return 0;
}