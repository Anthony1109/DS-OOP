#include <iostream>
#include <string>
#include "111611048_Date.h"
#include <ctime>
using namespace std;

Date::Date(int day, int month, int year){
    setDay(day);
    setMonth(month);
    setYear(year);
}

Date::~Date(){}

int Date::getDay(){
    return day;
}
int Date::getMonth(){
    return month;
}
int Date::getYear(){
    return year;
}

void Date::setDay(int day){
    day = (day < 1 || day > 31) ? 1 : day;
    this->day = day;
}
void Date::setMonth(int month){
    month = (month < 1 || month > 12) ? 1 : month;
    this->month = month;
}
void Date::setYear(int year){
    year = (year < 0) ? 1900 : year;
    this->year = year;
}

Date Date::DateAfter(int days){
    Date newDate = *this;
    newDate.addDays(days);
    return newDate;
}
Date Date::DateBefore(int days){
    Date newDate = *this;
    newDate.addDays(-days);
    return newDate;
}

string Date::days(){
    const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return daysOfWeek[dayOfWeek()];
}

int Date::numberOfDays(){
    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

void Date::printMonthCalendar(){
    const char* monthNames[] = { "January", "February", "March", "April", "May", "June",
                                    "July", "August", "September", "October", "November", "December" };

    cout << "--------------" << monthNames[month - 1] << "--------------" << endl;
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    int startDay = getFirstDayOfMonth();

    // Print leading spaces
    for (int i = 0; i < startDay; ++i) {
        cout << "     ";
    }

    int daysInCurrentMonth = numberOfDays();
    for (int i = 1; i <= daysInCurrentMonth; ++i) {
        cout << (i < 10 ? " " : "") << i << "   ";
        if ((i + startDay) % 7 == 0) {
            cout << "\n";
        }
    }
    cout << endl;
}

bool Date::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void Date::addDays(int days) {
    day += days;
    while (day > numberOfDays()) {
        day -= numberOfDays();
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += numberOfDays();
    }
}

int Date::dayOfWeek() {
    struct tm time_in = { 0, 0, 0, day, month - 1, year - 1900 };
    mktime(&time_in);
    return time_in.tm_wday;
}

int Date::getFirstDayOfMonth() {
    struct tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
    mktime(&time_in);
    return time_in.tm_wday;
}