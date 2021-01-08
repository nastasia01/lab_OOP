#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
class Date_time
{
public:
	Date_time();
	Date_time(int _day, int _month, int _year, int _sec, int _min, int _hour); //Конструктор с параметрами
	~Date_time(); // Деструктор
	Date_time(const Date_time& o);
	Date_time& operator= (const Date_time& date);
	operator const char* ();
	friend int operator+(Date_time& day, Date_time& day2);
	friend int operator-(Date_time& hour, Date_time& hour2);
	friend ostream& operator<< (ostream& os, Date_time& str);
	friend ofstream& operator<< (ofstream& os, Date_time& p);
	friend istream& operator>> (istream& is, Date_time& p);
	void WriteInBinary(ofstream& f_in);
	void ReadBinary(ifstream& f_in);
	void ReadFromFile(ifstream& f_out, Date_time& str);
	const char* getWeek();
	int dateToDays();
	int getDay();
	int getMonth();
	int getYear();
	void setWeek(const char* w);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void nextDay();
	void lastDay();
	void print();
	int getSec();
	int getMin();
	int getHour();
	void setSec(int s);
	void setMin(int mi);
	void setHour(int h);
	void nextMin();
	void lastMin();
	char* to_String1();
	

protected:
	int hour;
	int sec;
	int min;
	int day;
	int days;
	int month;
	int year;
	char* str;
	static const int s = 12;
	int mDays[s] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

};
