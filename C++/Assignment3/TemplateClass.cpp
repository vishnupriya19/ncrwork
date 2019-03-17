#include<stdio.h>
#include<iostream>
using namespace std;
#define SIZE 100
template<class T>
class Stack
{
	int top;
	T sta[SIZE];
public:
	Stack()
	{
		top = -1;
	}
	void push(T ele)
	{
		if (top == (SIZE - 1))
		{
			cout << "Overflow";
			return;
		}
		sta[++top] = ele;
	}
	T pop()
	{
		if (top == -1)
		{
			cout << "Underflow";
			return -1;
		}
		else
			return sta[top--];
	}
	T peek()
	{
		if (top == -1)
		{
			cout << "Underflow";
			return -1;
		}
		else
			return sta[top];
	}
	void display()
	{
		int i;
		for (i = 0; i <= top; i++)
			cout << sta[i] << " ";
		cout << "\n";
	}
};
int main()
{
	Stack<int> s;
	cout << "Integer stack\n";
	s.push(5);
	s.push(10);
	s.display();
	cout<<s.peek()<<endl;
	cout << s.pop() << endl;
	cout << "Character stack\n";
	Stack<char> s1;
	s1.push('a');
	s1.push('b');
	s1.display();
	cout << s1.peek() << endl;
	cout << s1.pop() << endl;
	return 0;
}