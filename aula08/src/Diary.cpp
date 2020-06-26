#include "Diary.h"
#include "HoraDataAtual.h"
#include <iostream>
#include <fstream>

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary()
{
    delete[] messages;
}

//gravar mensagens
void Diary::write()
{
   // falta fazer
}

// adicionar mensagen 
void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        return;
    }

    Message m;
    //mesagens
    m.content = message;
    // dia e hora formatado 
    m.date.set_from_string(get_current_date());
    m.date.set_from_string(get_current_time());

    messages[messages_size] = m;
    messages_size++;
}




