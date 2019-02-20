#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class Stack
{
	struct node *start;
public:
	Stack();
	void push(int);
	int pop();
	int peek();
	void display();
	~Stack();
};
Stack::Stack()
{
	start = NULL;
}
void Stack::push(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int Stack::pop()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp = start;
		x = temp->data;
		start = start->next;
		delete temp;
	}
	else
		cout << "Stack empty\n";
	return x;
}
int Stack::peek()
{
	int x = -999;
	if (start != NULL)
	{
		x = start->data;
	}
	else
		cout << "stack empty\n";
	return x;
}
void Stack::display()
{
	struct node *curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << "\n";
}
Stack::~Stack()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
}
int main()
{
	Stack s;
	int c,ele;
	while (1)
	{
		cout << "enter choice 1.push 2.pop 3.peek 4.display 5.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to push\n";
			cin >> ele;
			s.push(ele);
			break;
		case 2:ele = s.pop();
			cout << "poped ele = " << ele;
			break;
		case 3:ele = s.peek();
			cout << "peeked ele = " << ele;
			break;
		case 4:s.display();
			break;
		}
		if (c == 5)
			break;
	}
	return 0;
}