#include "App.h"
#include "Diary.h"
#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

//iniciar
int App::run(int argc, char* argv[]){  
   
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } 
        else {
            add(argv[2]);
        }
    } 
    else if (action == "list") {
        list_messages();
    } 
    else if (action == "search") {
        if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
    } 
    else {
        return show_usage(argv[0]);
    }

    return 0;
}


void App::add()
{
    std::string message;
    std::cout << "Insira a mensagem: " << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
    std::cout << "Mensagem cadastrada com sucesso!" << std::endl;

}

void App::list_messages(){        
      for (Message& message : diary.messages) {
        std::cout << "- " << message.content << std::endl;
    }
}


void App::search(){
    std::string what;
    std::cout << "Pesquisar: ";
    std::getline(std::cin, what);

    search(what);
}

void App::search(const std::string& what){
    std::vector <Message*> msg_encontrada = diary.search(what);
    if(msg_encontrada.empty()){ // Testa se o contêiner do vetor está vazio.
        std::cout << " Mensagem não encontrada!" << std::endl;
        return;
    }
    for(auto i : msg_encontrada) {
            std::cout << i->date.to_string() << " - " << i->time.to_string() << " - " << i->content << std::endl;
        }
  //  std::cout << message->date.to_string() << " - "<< message->time.to_string() << " - " << message->content << std::endl;
 
}

int App::show_usage(const std::string nomedoprograma)
{
    std::cout << "Como usar "<< std::endl<< std::endl;
    std::cout <<"      " <<nomedoprograma<<" add [informação]" << std::endl;
    std::cout << "Ou: "<<"\n"; 
    std::cout <<"      "<<nomedoprograma<<" list" << std::endl;
    return 1;
}