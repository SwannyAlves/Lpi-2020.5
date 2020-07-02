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
    size_t messages_size;
    size_t messages_capacity;
    Message* search(const std::string& what);

    void add(const std::string& message);
    void addarq(const Message& message);
    void write(); // gravar mensagens
    void passaUmNovoDiary(const std::string& filename);
    void aumentarCapacidade();
};
#endif
