#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary(); // destruir coisas alocadas

    std::string filename;
    Message* messages;
    Message* newmessages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void addarq(const Message& message);
    void write(); // gravar mensagens
    void read(); // ler mensagens 
    void passaUmNovoDiary(const std::string& filename);
};
#endif
