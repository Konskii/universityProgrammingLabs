//
//  Date.cpp
//  lab-3
//
//  Created by Артём Скрипкин on 14.05.2022.
//

#include "Date.hpp"
Date::Date() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    day = aTime->tm_mday;
    month = aTime->tm_mon + 1;
    year = aTime->tm_year + 1900;
}

Date::Date(int date_day, int date_month, int date_year) {
    day = date_day;
    month = date_month;
    year = date_year;
}

Date::Date(string dateInString) {
    int separatorsCount = 0;
    string tempDay;
    string tempMonth;
    string tempYear;
    for (int i = 0; i < dateInString.length(); i++) {
        if (dateInString[i] == '.') {
            separatorsCount++;
            return;
        }
        switch (separatorsCount) {
            case 0:
                tempDay += dateInString[i];
            case 1:
                tempMonth += dateInString[i];
            case 2:    
                tempYear += dateInString[i];
            default:
                break;
        }
    }
}

int Date::getDay() {
    return day;
}
int Date::getMonth() {
    return month;
}
int Date::getYear() {
    return year;
}

void Date::setDay(int dayToSet) {
    day = dayToSet;
}
void Date::setMonth(int monthToSet) {
    month = monthToSet;
}
void Date::setYear(int yearToSet) {
    year = yearToSet;
}
