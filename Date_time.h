#pragma once
class Date_time
{
public:
	Date_time();
	Date_time(int _day, int _month, int _year, int _sec, int _min, int _hour); //Конструктор с параметрами
	~Date_time(); // Деструктор
	Date_time(const Date_time &o);
	int dateToDays();
	int getDay();
	int getMonth();
	int getYear();
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
	char* to_String2();
	void primer1();
	void primer2();

private:
	int sec;
	int min;
	int hour;
	int day;
	int month;
	int year;
	static const int s = 12;
	int mDays[s] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

};

