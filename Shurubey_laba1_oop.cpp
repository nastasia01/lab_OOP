#include "Date_time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Date_time primer1;
	primer1.setYear(2019);
	primer1.setMonth(5);
	primer1.setDay(21);
	primer1.nextDay();
	primer1.setHour(19);
	primer1.setMin(59);
	primer1.setSec(13);
	primer1.nextMin();
	primer1.print();
	Date_time primer2;
	primer2.setYear(2020);
	primer2.setMonth(2);
	primer2.setDay(29);
	primer2.lastDay();
	primer2.setHour(5);
	primer2.setMin(0);
	primer2.setSec(25);
	primer2.lastMin();
	primer2.print();

}
