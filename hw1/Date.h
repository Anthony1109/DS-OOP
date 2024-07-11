#include <iostream>
#include <string>
using namespace std;

class Date
{
  public:
    Date(int day, int month, int year)
    {
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
            throw std::invalid_argument("Invalid date values provided.");
        }
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    ~Date(){}

    /*Get function for accessing private member*/
    int getDay();
    int getMonth();
    int getYear();

    /*Set function for updating private member*/
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    /*A Function that returns the date after a given date
        For e.g-
        
        today is 8/3/2018 (Day/Month/Year)
        DateAfter(3) should return a date of 11/3/2018 */
    Date DateAfter(int days);

    /*A Function that returns the date after a given date
        For e.g-
        
        today is 8/3/2018 (Day/Month/Year)
        DateBefore(3) should return a date of 5/3/2018 */
    Date DateBefore(int days);

    /*A Function that returns the day of a date
        For e.g-
        
        if the date is 8/3/2018, then the day() function
        should return "Thursday"
    */
    string days();

    /* A Function to return the number of days in
        Current Month.
        
        Month Number     Name        Number of Days
        0                January     31
        1                February    28 (non-leap) / 29 (leap)
        2                March       31
        3                April       30
        4                May         31
        5                June        30
        6                July        31
        7                August      31
        8                September   30
        9                October     31
        10               November    30
        11               December    31*/
    int numberOfDays();

    /* Function to print a calendar of the current month.
    Just like what you see on a calendar. An example is like

   --------------March--------------
   Sun  Mon  Tue  Wed  Thu  Fri  Sat
                        1    2    3
    4    5    6    7    8    9   10
   11   12   13   14   15   16   17
   18   19   20   21   22   23   24
   25   26   27   28   29   30   31
    
   */
    void printMonthCalendar();

  private:
    /*Current Date*/
    int day;
    int month;
    int year;
    bool isLeapYear(int year){
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }
    void addDays(int days) {
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

    int dayOfWeek() {
        int d = day, m = month, y = year;
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        return (d + 2*m + (3*(m+1))/5 + y + y/4 - y/100 + y/400) % 7;
    }

    int getFirstDayOfMonth() {
        int m = month, y = year;
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        return (1 + 2*m + (3*(m+1))/5 + y + y/4 - y/100 + y/400) % 7;
    }
};

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
    if (day < 1 || day > 31) {
        throw std::invalid_argument("Invalid day value provided.");
    }
    this->day = day;
}
void Date::setMonth(int month){
    if (month < 1 || month > 12) {
        throw std::invalid_argument("Invalid month value provided.");
    }
    this->month = month;
}
void Date::setYear(int year){
    if (year < 0) {
        throw std::invalid_argument("Invalid year value provided.");
    }
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