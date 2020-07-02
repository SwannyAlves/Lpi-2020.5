#ifndef W5N_MESSAGE_H
#define W5N_MESSAGE_H

#include "Date.h"
#include "Time.h"
#include "HoraDataAtual.h"

#include <string>

struct Message
{
    std::string content;
    Date date;
    Time time;

    void data(std::string date);
    void horario(std::string time);

    std::string data();
    std::string hora();


};
#endif
