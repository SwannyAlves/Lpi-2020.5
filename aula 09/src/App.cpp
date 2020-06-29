#include "App.h"
#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[]){  
   
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

int App::show_usage(const std::string nomedoprograma)
{
    std::cout << "Como usar "<< std::endl<< std::endl;
    std::cout <<"      " <<nomedoprograma<<" add [informação]" << std::endl;
    std::cout << "Ou: "<<"\n"; 
    std::cout <<"      "<<nomedoprograma<<" list" << std::endl;
    return 1;
}
