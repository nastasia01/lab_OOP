#include "Date_time.h"
#include <iostream>
#include <string>
using namespace std;

Date_time::Date_time() {}
Date_time::Date_time(int _day, int _month, int _year, int _sec, int _min, int _hour)
{
	day = _day;
	month = _month;
	year = _year;
	sec = _sec;
	min = _min;
	hour = _hour;
}

Date_time::~Date_time() {}

int Date_time::dateToDays()
{
	int days = 0;
	days = day;
	for (int i = 0; i < month - 1; i++) {
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
	if (y >= 1100 && y <= 2100)
		year = y;
}
void Date_time::setMonth(int m)
{
	if (m <= 12)
	month = m;
}
void Date_time::setDay(int d)
{
	if (d % 4 == 0 && month == 2 && d <= 29)
		day = d;
	else if (d <= mDays[month - 1])
		day = d;
}

void Date_time::nextDay()
{
	if (day + 1 <= mDays[month]) day++;
	else if (month < 12) { day = 1; month++; }
	else { day = 1; month = 1; year++; }
}
void Date_time::lastDay()
{
	if (day - 1 >= 1) day--;
	else if (day < 1) { day = mDays[month - 1]; month--; }
	else { day = 31; month = 12; year--; }
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
{   if (s < 60)
	   sec = s;
}
void Date_time::setMin(int mi)
{
	if (mi < 60)
	   min = mi;
}

void Date_time::setHour(int h)
{
	if (h < 24)
	hour = h;
}
void Date_time::nextMin()
{
	if ((min + 1) < 60) min++;
	else if ((hour + 1) < 24 && (min + 1) == 60) { hour += 1; min = 0; }
	else {		hour = 0;  min = 0;}
}
void Date_time::lastMin()
{
	if ((min - 1) >= 0) min--;
	else if ((min - 1) < 0 && (hour - 1) > 0) { hour--; min = 59; }
	else { hour = 23; min = 59; }
}
void Date_time::print() {
	cout << day << "." << month << "." << year << endl;
	cout << hour << ":" << min << ":" << sec << endl;
}
