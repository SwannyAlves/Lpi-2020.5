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

std:: string Date::to_string(){
    std::stringstream dia_stream;
    std:: string dia;

    if(day <10){
        dia_stream << '0';
    }
    dia_stream << day << '/';
    if(month < 10){
        dia_stream << '0';
    }
    dia_stream << month << '/'<< year;

     dia_stream >> dia;
     return dia;

}