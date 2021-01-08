#include "American_date.h"
#include <iostream>
#include <string>
using namespace std;

char* American_date::getdd()
{
	return dd;
}
void American_date::setdd(const char* d)
{
	delete[] dd;
	dd = new char[strlen(d) + 1];
	strcpy(dd, d);
}
char* American_date::toString()
{
	char* str = new char[1000];
	sprintf(str, "%d/%d/%d %d:%d:%d %s", this->month, this->day, this->year, this->hour, this->min, this->sec, this->dd);
	return str;
}
