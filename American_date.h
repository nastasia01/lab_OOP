#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Date_time.h"
using namespace std;
class American_date :
    public Date_time
{
public:
    American_date() : Date_time() {
        dd = new char[3];
        strcpy(dd, " ");
    }

    American_date(int d, int m, int y, int h, int mm, int s) : Date_time(d, m, y, h, mm, s) {
        dd = new char[4];
        if (h > 12) {
            strcpy(dd, "PM");
            h -= 12;
        }
        else strcpy(dd, "AM");
    }

    American_date(const American_date& o) : Date_time(o) {
        dd = new char[strlen(o.dd) + 1];
        strcpy(dd, o.dd);
    }

    ~American_date() {
        cout << __FUNCTION__ << endl;
        delete[] dd;
    }

    char* getdd();
    void setdd(const char* d);
    char* toString();

private:
    char* dd;

};

