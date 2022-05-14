//
//  Date.hpp
//  lab-3
//
//  Created by Артём Скрипкин on 14.05.2022.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <chrono>
using namespace std;

class Date {
public:
    //MARK: - inits
    Date(int date_day, int date_month, int date_year);
    /// format 01.01.1999 or 1.1.1999
    Date(string dateInString);
    /// inits with current date
    Date();
    
    //MARK: - Methods
    void setDay(int dayToSet);
    void setMonth(int monthToSet);
    void setYear(int yearToSet);
    int getDay();
    int getMonth();
    int getYear();
    friend bool operator==(const Date& lhs, const Date& rhs) {
        if (lhs.day == rhs.day &&
            lhs.month == rhs.month &&
            lhs.year == rhs.year) 
        {
            return true;
        }
        return false; 
    };
    int daysTo(const Date &d) const {
        auto ourDate = std::chrono::year{year}/month/day;
        auto theirDate = std::chrono::year{year}/month/day;
        auto diffrence = std::chrono::sys_days{theirDate} - std::chrono::sys_days{ourDate};
        return diffrence.count();
    }
    
private: 
    int day, month, year;
};

#endif /* Date_hpp */
