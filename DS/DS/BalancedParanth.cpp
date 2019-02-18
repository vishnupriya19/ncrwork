#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int main()
{
	char str[50];
	Stack sta;
	int i,f=0;
	cout << "enter string\n";
	cin >> str;
	sta.getSize(strlen(str));
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
			sta.push(str[i]);
		if ((str[i] == ')' && sta.peek() == '(') || (str[i] == '}' && sta.peek() == '{') || (str[i] == ']' && sta.peek() == '['))
			sta.pop();
		else if ((str[i] == ')' && sta.peek() != '(') || (str[i] == '}' && sta.peek() != '{') || (str[i] == ']' && sta.peek() != '['))
		{
			f = 1;
			break;
		}
		//sta.display();

	}
	if ((f == 0) && sta.isEmpty())
		cout << "Balanced paranthesis" << endl;
	else
		cout << "Unbalanced paranthesis\n";
	return 0;
}