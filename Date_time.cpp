#include "Date_time.h"
#include <iostream>
#include <string>
using namespace std;

Date_time::Date_time()
{
	Date_time::day = 1;
	Date_time::month = 1;
	Date_time::year = 1970;
	Date_time::sec = 0;
	Date_time::min = 0;
	Date_time::hour = 0;
	//Date_time::mDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

}
Date_time::Date_time(int _day, int _month, int _year, int _sec, int _min, int _hour)
{
	day = _day;
	month = _month;
	year = _year;
	sec = _sec;
	min = _min;
	hour = _hour;
}
Date_time::Date_time(const Date_time &o) {
	int d = o.day;
	int m = o.month;
	int y = o.year;
	int s = o.sec;
	int mm = o.min;
	int h = o.hour;
}
Date_time::~Date_time() {
	cout << __FUNCTION__ << endl;
}

int Date_time::dateToDays()
{
	int days = 0;
	days = day;
	for (int i = 0; i < month - 1; i++)
	{
		days += mDays[i];
	}
	days += year * 365 + year / 4 - year / 100 + year / 400;
	return days;
}
int Date_time::getDay()
{
	return day;
}
int Date_time::getMonth()
{
	return month;
}

int Date_time::getYear()
{
	return year;
}

void Date_time::setYear(int y)
{
	try
	{
		if (y >= 1100 && y <= 2100)
			year = y;
	}
	catch(int)
	{
		cout << "Error" << endl;
	}
}
void Date_time::setMonth(int m)
{
	try
	{
		if (m <= 12)
			month = m;
	}
	catch (int)
	{
		cout << "Error" << endl;
	}

}
void Date_time::setDay(int d)
{
	try
	{
		if (d % 4 == 0 && month == 2 && d <= 29)
			day = d;
		else if (d <= mDays[month - 1])
			day = d;
	}
	catch (int)
	{
		cout << "Error" << endl;
	}
}


void Date_time::nextDay()
{
	if (day + 1 <= mDays[month])
		day++;
	else if (month < 12)
	{
		day = 1;
		month++;
	}
	else { day = 1; month = 1; year++; }
}
void Date_time::lastDay()
{
	if ((day - 1) >= 1)
		day--;
	else if ((day - 1) == 0)
	{
		day = mDays[month - 1];
		month--;
	}
	else if ((day - 1) == 0 && (month - 1) == 0)
	{
		day = 31;
		month = 12;
		year--;
	}

}

int Date_time::getSec()
{
	return sec;
}
int Date_time::getMin()
{
	return min;
}

int Date_time::getHour()
{
	return hour;
}

void Date_time::setSec(int s)
{   
	try
	{
		if (s < 60)
			sec = s;
	}
	catch (int)
	{
		cout << "Error" << endl;
	}
}
void Date_time::setMin(int mi)
{
	try
	{
		if (mi < 60)
			min = mi;
	}
	catch (int)
	{
		cout << "Error" << endl;
	}
}

void Date_time::setHour(int h)
{
	try
	{
		if (h < 24)
			hour = h;
	}
	catch (int)
	{
		cout << "Error" << endl;
	}
}
void Date_time::nextMin()
{
	if ((min + 1) < 60)
		min++;
	else if ((hour + 1) < 24 && (min + 1) == 60)
	{
		hour += 1;
		min = 0;
	}
	else
	{
		hour = 0;
		min = 0;
	}
}
void Date_time::lastMin()
{
	if ((min - 1) >= 0)
		min--;
	else if ((min - 1) < 0 && (hour - 1) > 0)
	{
		hour--;
		min = 59;
	}
	else
	{
		hour = 23;
		min = 59;
	}
}

char* Date_time::to_String1()
{
	char* str = new char[100];

	sprintf_s(str, 100, "New date %d.%d.%d", this->day, this->month, this->year);
		return str;
}
char* Date_time::to_String2()
{
	char* str = new char[100];

	sprintf_s(str, 100, "   new time %d.%d.%d", this->hour, this->min, this->sec);
		
		return str;
}

void Date_time::print() {
	cout << Date_time::to_String1() << Date_time::to_String2() << endl;
}

