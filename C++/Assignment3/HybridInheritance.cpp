#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Person
{
	char *name;
	int age;
public:
	Person()
	{
		name = NULL;
		age = 0;
	}
	Person(char *n, int a)
	{
		name = new char[strlen(n)];
		strcpy(name, n);
		age = a;
	}
	void getPersonDetails()
	{
		char s[50];
		cout << "enter name and age\n";
		cin >> s;
		name = new char[strlen(s)];
		strcpy(name, s);
		cin >> age;
	}
	void displayPersonDetails()
	{
		cout << "Name = " << name << " age = " << age << endl;
	}
	~Person()
	{
		if (name != NULL)
			delete name;
	}
};
class Physique :virtual public Person
{
	int height;
	int weight;
public:
	Physique()
	{
		height = weight = 0;
	}
	Physique(int ht, int wt)
	{
		height = ht;
		weight = wt;
	}
	void getPhysique()
	{
		cout << "Enter height and weight\n";
		cin >> height>>weight;
	}
	void displayPhysique()
	{
		cout << "Height = " << height << " Weight = " << weight << endl;
	}
};
class Family :virtual public Person
{
	int numChildren;
	char *religion;
public:
	Family()
	{
		religion = NULL;
	}
	Family(int nC, char *reli)
	{
		numChildren = nC;
		religion = new char[strlen(reli)];
		strcpy(religion, reli);
	}
	void getFamily()
	{
		char s[25];
		cout << "Enter number of children and Religion" << endl;
		cin >> numChildren;
		cin >> s;
		religion = new char[strlen(s)];
		strcpy(religion, s);
	}
	void displayFamily()
	{
		cout << "Number of children = " << numChildren << " Religion = " << religion << endl;
	}
	~Family()
	{
		if (religion != NULL)
			delete religion;
	}
};
class Employee :public Family,public Physique
{
	int empno;
	int salary;
public:
	Employee()
	{
		empno = salary = 0;
	}
	Employee(int eno, int sal)
	{
		empno = eno;
		salary = sal;
	}
	void getEmployee()
	{
		cout << "Enter employee number and salary\n";
		cin >> empno >> salary;
	}
	void displayEmployee()
	{
		cout << "Employee number = " << empno << " Salary = " << salary << endl;
	}
};
int main()
{
	Employee emp;
	emp.getPersonDetails();
	emp.getPhysique();
	emp.getFamily();
	emp.getEmployee();
	emp.displayPersonDetails();
	emp.displayPhysique();
	emp.displayFamily();
	emp.displayEmployee();
	return 0;
}