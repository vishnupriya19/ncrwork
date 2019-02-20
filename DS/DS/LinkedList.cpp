#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
struct node *next;
};
class List
{
	struct node *start;
public:
	List();
	void Insert_First(int);
	void Insert_Last(int);
	void Insert_After(int, int);
	void Insert_Before(int, int);
	int Delete_First();
	int Delete_Last();
	void Delete_Spec(int);
	void Traverse_Forward();
	void Traverse_Backward();
	void Reverse();
	~List();
	friend void print(struct node*);
};
List::List()
{
	start = NULL;
}
void List::Insert_First(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void List::Insert_Last(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		struct  node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
void List::Insert_After(int sele, int ele)
{
	struct node *curr = start;
	while (curr != NULL && curr->data != sele)
		curr = curr->next;
	if (curr != NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = curr->next;
		curr->next = temp;
	}
	else
		cout << "search ele not found\n";
}
void List::Insert_Before(int sele, int ele)
{
	if (start != NULL)
	{
		if (start->data == sele)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next != NULL && curr->next->data != sele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "Search ele not found\n";
		}
	}
	else
		cout << "List empty\n";
}
int List::Delete_First()
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
		cout << "List empty\n";
	return x;
}
int List::Delete_Last()
{
	int x = -999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			cout << "Hello";
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			curr->next = NULL;
			delete curr->next;
		}
	}
	else
		cout << "List is empty\n";
	return x;
}
void  List::Delete_Spec(int ele)
{
	if (start != NULL)
	{
		if (start->data == ele)
		{
			struct node *temp = start;
			start = start->next;
			cout << temp->data << " is deleted\n";
			delete temp;
		}
		else
		{
			struct node *curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				struct node *temp = curr->next;
				curr->next = curr->next->next;
				cout << temp->data << " is deleted\n";
				delete temp;
			}
			else
				cout << "ele not found\n";
		}
	}
	else
		cout << "List empty\n";

}
void List::Traverse_Forward()
{
	struct node *curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}
void print(struct node *curr)
{
	if (curr == NULL)
		return;
	print(curr->next);
	cout << curr->data << " ";
}
void List::Traverse_Backward()
{
	print(start);
}
List::~List()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
}
void List::Reverse()
{
	struct node *rev = NULL, *temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		temp->next = rev;
		rev = temp;
	}
	start = rev;
}
int main()
{
	int c, ele, sele; List l;
	while(1)
	{
	cout << "enter 1.insert at begin 2.insert at end 3.insert after 4.insert before 5.delete first 6.delete last 7.delete specific 8.traverse forward 9.traverse backward 10.reverse 11.exit\n";
	cin >> c;
	switch (c)
	{
	case 1:cout << "enter ele to insert";
		cin >> ele;
		l.Insert_First(ele);
		break;
	case 2:cout << "enter ele to insert";
		cin >> ele;
		l.Insert_Last(ele);
		break;
	case 3:cout << "enter ele to insert";
		cin >> ele;
		cout << "enter search ele";
		cin >> sele;
		l.Insert_After(sele, ele);
		break;
	case 4:cout << "enter ele to insert";
		cin >> ele;
		cout << "enter search ele";
		cin >> sele;
		l.Insert_Before(sele, ele);
		break;
	case 5:ele = l.Delete_First();
		cout << "Deleted ele = " << ele;
		break;
	case 6:ele = l.Delete_Last();
		cout << "Deleted ele = " << ele;
		break;
	case 7:cout << "enter ele to delete";
		cin >> ele;
		l.Delete_Spec(ele);
		break;
	case 8:l.Traverse_Forward();
		break;
	case 9:l.Traverse_Backward();
		break;
	case 10:l.Reverse();
		break;
	}
	if (c == 11)
		break;
}
	return 0;
}