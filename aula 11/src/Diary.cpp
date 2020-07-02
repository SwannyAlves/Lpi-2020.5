#include "Diary.h"
#include "HoraDataAtual.h"
#include "Message.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

//alocar novas mensagens
Diary::Diary(const std::string& name) : filename(name){
    passaUmNovoDiary(filename);
}
//destruir \o
Diary::~Diary()
{
    write();
}

// adicionar mensagen 
void Diary::add(const std::string& message)
{
    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    messages.push_back(m);

}

void Diary::addarq(const Message& message){
    messages.push_back(message);
}

void Diary::write(){
    std::ofstream arquivo_saida(filename);
    if (!arquivo_saida.is_open()) {
    	return;
  	}
	
  	for(Message& msg : messages){
  		std::string date_message = msg.date.to_string();
  		if(!dataexiste(filename, date_message)){
			arquivo_saida << "# " << date_message << std::endl;
		}
		std::string hora = msg.time.to_string();
		arquivo_saida << "- " << hora << " "<< msg.content << std::endl;
  	}
	
	
}


std::vector<Message*> Diary::search(const std::string& what){
	std::vector <Message*> msg_encontrada ;
    for(Message& m : messages){
		if(m.content.find(what,0) != std::string::npos){
			msg_encontrada.push_back(&m);
		}
	}
	return msg_encontrada;
}


void Diary::passaUmNovoDiary(const std::string& filename){
    Message m;

    std::ifstream arquivo(filename);
	if(!arquivo.is_open()){
		return;
	}
	std::string ler_linha;
	while (!arquivo.eof()) {

    	std::getline(arquivo, ler_linha);

    	if (ler_linha.size() == 0) { 
      		continue;
    	}

    	if(ler_linha[0] == '#'){
    		m.date.set_from_string(ler_linha.erase(0,2));
    		continue;
    	}

    	m.time.set_from_string(ler_linha.substr(2));
        m.content = ler_linha.substr(11);
    	addarq(m);
  	}

}

bool Diary::dataexiste(const std::string& filename, std::string titulo){
  std::ifstream arquivo_entrada(filename);
  std::string message;
  while (!arquivo_entrada.eof()) {
    std::getline(arquivo_entrada, message);
    if(message.size() != 0){      
      if(message[0] == '#' &&  message.erase(0,2) == titulo) {
        return true;
      } 
    }
  }
  return false;
}


