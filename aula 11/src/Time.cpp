#include "Time.h"
#include <string>
#include <sstream>

// converte uma string em hora 
void Time::set_from_string(const std:: string &time){
    
    std::stringstream stream(time);
    char discartar;

    stream >> hour;
    stream >> discartar;
    stream >> minute;
    stream >> discartar;
    stream >> second;
}



std:: string Time::to_string(){
    std::stringstream hora_stream;
    std:: string hora;


    if(hour < 10){
        hora_stream << '0';
    }
    hora_stream << hour << ":";
    if(minute < 10){
        hora_stream << '0';
    }
    hora_stream << minute << ":";
     if(second < 10){
        hora_stream << '0';
    }
    hora_stream << second;

    hora_stream >> hora;
     return hora;

}