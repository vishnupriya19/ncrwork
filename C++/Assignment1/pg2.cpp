#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Student
{
	char *studentName;
	char grade[30];
	int m[3];
public:
	void setData(char *s, char *g, int marks[3])
	{
		int i;
		studentName = (char*)malloc(sizeof(char)*(strlen(s) + 1));
		for (i = 0; i < 3; i++)
			m[i] = marks[i];
		strcpy(studentName, s);
		strcpy(grade,g);
	}
	float calculateAverage()
	{
		int i,s=0;
		for (i = 0; i < 3; i++)
			s = s + m[i];
		return s / 3;
	}
	void computeGrade()
	{
		float avg = calculateAverage();
		if (avg > 60)
			strcpy(grade, "firstclass");
		else if (avg > 50 && avg <= 60)
			strcpy(grade, "second class");
		else if (avg > 40 && avg <= 50)
			strcpy(grade, "third class");
		else
			strcpy(grade, "fail");
	}
	void displayData()
	{
		cout << "Name = " << studentName << "\nGrade = " << grade << "\nMarks = " << m[0] << " " << m[1] << " " << m[2];
	}

};
int main()
{
	Student s;
	int m[3] = { 80,90,80 };
	s.setData("vishnu priya", "not known", m);
	s.computeGrade();
	s.displayData();
	return 0;
}
