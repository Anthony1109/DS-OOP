#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

class Date {
public:
    Date(int day, int month, int year){
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    ~Date() {}

    /* Get function for accessing private member */
    int getDay() const{ return day; }
    int getMonth() const{ return month; }
    int getYear() const{ return year; }

    /* Set function for updating private member */
    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    /* A Function that returns the date after a given date */
    Date DateAfter(int days) {
        tm date = {};
        date.tm_mday = this->day + days;
        date.tm_mon = this->month - 1;  // tm_mon is 0-11
        date.tm_year = this->year - 1900; // tm_year is years since 1900
        mktime(&date);
        return Date(date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
    }

    /* A Function that returns the date before a given date */
    Date DateBefore(int days) {
        return DateAfter(-days);
    }

    /* A Function that returns the day of a date */
    string days() {
        tm date = {};
        date.tm_mday = this->day;
        date.tm_mon = this->month - 1;
        date.tm_year = this->year - 1900;
        mktime(&date);
        const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return daysOfWeek[date.tm_wday];
    }

    /* A Function to return the number of days in the current month */
    int numberOfDays() {
        const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && isLeapYear(year)) {
            return 29;
        }
        return daysInMonth[month - 1];
    }

    /* Function to print a calendar of the current month */
    void printMonthCalendar() {
        const char* monthNames[] = { "January", "February", "March", "April", "May", "June",
                                     "July", "August", "September", "October", "November", "December" };

        cout << "--------------" << monthNames[month - 1] << "--------------\n";
        cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        // Find the day of the week for the first day of the month
        tm date = {};
        date.tm_mday = 1;
        date.tm_mon = this->month - 1;
        date.tm_year = this->year - 1900;
        mktime(&date);
        int startDay = date.tm_wday;

        // Print leading spaces
        for (int i = 0; i < startDay; ++i) {
            std::cout << "     ";
        }

        int daysInCurrentMonth = numberOfDays();
        for (int i = 1; i <= daysInCurrentMonth; ++i) {
            cout << (i < 10 ? " " : "") << i << "   ";
            if ((i + startDay) % 7 == 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }

private:
    /* Check if a year is a leap year */
    bool isLeapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }

    /* Current Date */
    int day;
    int month;
    int year;
};


