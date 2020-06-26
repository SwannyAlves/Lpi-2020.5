#include "Time.h"
#include <string>
#include <sstream>


void Time::set_from_string(const std:: string &time){
    
    std::stringstream stream(time);
    char discartar;

    stream >> hour;
    stream >> discartar;
    stream >> minute;
    stream >> discartar;
    stream >> second;
}
