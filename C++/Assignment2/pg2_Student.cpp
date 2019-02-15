#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Student
{
	int rollno;
	char *name;
	int m[3];
	int tot;
	int grade;
public:
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, Student&);
	friend void calculate(Student[], int);
};
istream& operator>>(istream &cin, Student &s)
{
	char name[50]; int i;
	cout<<"enter rollno\n";
	cin >> s.rollno;
	cout << "enter name\n";
	cin >> name;
	s.name = new char[strlen(name)];
	strcpy(s.name, name);
	printf("enter 3 subject marks\n");
	for (i = 0; i < 3; i++)
		scanf("%d", &s.m[i]);
	return cin;
}
ostream& operator<<(ostream& cout, Student &s)
{
	int i;
	cout << "Roll No = " << s.rollno << endl;
	cout << "Name = " << s.name << endl;
	cout << "Marks = ";
	for (i = 0; i < 3; i++)
		cout << s.m[i] << " ";
	cout << endl;
	cout << "Total = " << s.tot << endl;
	cout << "Grade = " << s.grade << endl;
	return cout;
}
void calculate(Student s[], int n)
{
	int i,j,sum=0,g;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
			sum = sum + s[i].m[j];
		s[i].tot = sum;
		if (s[i].tot/3 > 90)
			g = 10;
		else if (s[i].tot/3 > 80 && s[i].tot/3 <= 90)
			g = 9;
		else if (s[i].tot/3 > 70 && s[i].tot/3 <= 80)
			g = 8;
		else
			g = 7;
		s[i].grade = g;
	}
}
int main()
{
	int n,i;
	Student s1[10];
	cout << "enter no of arrays u want to create\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> s1[i];
	calculate(s1, n);
	cout << "\n";
	for (i = 0; i < n; i++)
		cout << s1[i];
	return 0;
}