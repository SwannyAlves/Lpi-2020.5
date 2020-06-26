#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

Date::Date() : day(0), month(0), year(0){
}

void Date::set_from_string(const std:: string &date){
    std::stringstream stream(date);

    char discartar;

    stream >> day;
    stream >> discartar;
    stream >> month;
    stream >> discartar;
    stream >> year;
}