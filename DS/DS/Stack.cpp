#include<stdio.h>
#include<stdlib.h>
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
int Stack :: pop()
{
	int x = -999;
	if (!isEmpty())
		x = s[top--];
	return x;
}
int Stack :: peek()
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
	int n,c,ele;
	Stack sta;
	cout << "enter size of stack" << "\n";
	cin >> n;
	sta.getSize(n);
	while (1)
	{
		cout << "enter 1.push 2.pop 3.display 4.peek 5.exit" << "\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to push" << "\n";
			cin >> ele;
			sta.push(ele);
			break;
		case 2:ele = sta.pop();
			cout << "popped ele" << ele << endl;
			break;
		case 3:sta.display();
			break;
		case 4:sta.peek();
			break;
		}
		if (c == 5)
			break;
	}
	return 0;
}