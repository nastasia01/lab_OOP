#pragma once
#include "Date_time.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Meeting_date :
    public Date_time
{
public:
    Meeting_date() :Date_time() {
        event = new char[3];
        strcpy(event, " ");
    }

    Meeting_date(int d, int m, int y, int h, int mm, int s, const char* ev) : Date_time(d, m, y, h, mm, s) {
        event = new char[strlen(ev) + 1];
        strcpy(event, ev);
    }

    Meeting_date(const  Meeting_date& o) : Date_time(o) {
        event = new char[strlen(o.event) + 1];
        strcpy(event, o.event);
    }

    ~Meeting_date() {
        cout << __FUNCTION__ << endl;
        delete[] event;
    }

    char* getEvent();
    void setEvent(const char* d);
    char* toString();

private:
    char* event;
};

