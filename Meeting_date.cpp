#include "Meeting_date.h"
#include <iostream>

char* Meeting_date::getEvent() {
	return event;
}

void Meeting_date::setEvent(const char* d) {
	delete[] event;
	event = new char[strlen(d) + 1];
	strcpy(event, d);
}

char* Meeting_date::toString() {
	char* str = new char[1000];
	sprintf(str, "Событие: %s \nЗапланировано на: %d/%d/%d %d:%d:%d ", this->event, this->day, this->month, this->year, this->hour, this->min, this->sec);
	return str;
}