#include "Date_time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	//Date_time obj;
	Date_time primer1;
	primer1.setYear(2020);
	primer1.setMonth(2);
	primer1.setDay(28);
	primer1.nextDay();
	primer1.setHour(19);
	primer1.setMin(59);
	primer1.setSec(13);
	primer1.nextMin();
	primer1.print();
	//cout << obj.to_String() << endl;
	Date_time primer2;
	primer2.setYear(2020);
	primer2.setMonth(9);
	primer2.setDay(1);
	primer2.lastDay();
	primer2.setHour(5);
	primer2.setMin(0);
	primer2.setSec(25);
	primer2.lastMin();
	primer2.print();

}
