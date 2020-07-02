#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"
#include <vector>
#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary(); // destruir coisas alocadas

    std::string filename;
    std::vector <Message> messages;
    
    void add(const std::string& message);
    void addarq(const Message& message);
    std::vector<Message*> search(const std::string& what);
    void write(); // gravar mensagens
    void passaUmNovoDiary(const std::string& filename);
    bool check_date(const std::string& filename, std::string data);


};
#endif
