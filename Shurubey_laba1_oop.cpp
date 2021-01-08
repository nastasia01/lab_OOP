#include "Date_time.h"
#include "American_date.h"
#include "Meeting_date.h"
#include "Tests.h"
#include <iostream>
#include <fstream>
	using namespace std;

	int main() {
		setlocale(LC_ALL, "Rus");
		/*Tests primer1, primer2;
		//primer1.primer1();
		primer2.primer2();*/
		American_date obj1(15, 8, 2002, 14, 1, 1);
		cout << obj1.toString() << endl;

		cout << endl;

		Meeting_date obj2(31, 12, 2020, 23, 59, 59, "Новый год");
		cout << obj2.toString() << endl;

		cout << endl;
	}