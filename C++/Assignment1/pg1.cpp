#include<stdio.h>
#include<iostream>
using namespace std;
class Time
{
	int hours, minutes, seconds;
	public:
	Time()
	{
		hours = minutes = seconds = 0;
	}
	Time(int h, int m, int s)
	{
		hours = h; minutes = m; seconds = s;
	}
	void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << "\n";
	}
	void add(Time &t1, Time &t2)
	{
		//Time t;
		hours = t1.hours + t2.hours;
		minutes = t1.minutes + t2.minutes;
		seconds = t1.seconds + t2.seconds;
	}
};
int main()
{
	Time t1(7, 12, 50), t2(23, 06, 50), t3;
	t3.add(t1, t2);
	t3.display();
	return 0;
}