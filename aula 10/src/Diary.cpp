#include "Diary.h"
#include "HoraDataAtual.h"
#include "Message.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

//alocar novas mensagens
Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity]; 
    passaUmNovoDiary(filename);
}
//destruir \o
Diary::~Diary()
{
    delete[] messages;
}

// adicionar mensagen 
void Diary::add(const std::string& message)
{
    if(messages_size >= messages_capacity){
		aumentarCapacidade();
	}

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    messages[messages_size] = m;
    messages_size++;
}

void Diary::addarq(const Message& message){
    if(messages_size >= messages_capacity){
		aumentarCapacidade();
	}
	messages[messages_size] = message;
	messages_size++;

}



void Diary::write(){
    Message m = messages[messages_size-1];

    std::ofstream file_out(filename, std::ios::app);
    

    if (!file_out.is_open()){
            std::cout << "Arquivo não existente ou sem permissão de leitura. \n";
            return ;
    }

    std::string dataHoje = m.date.to_string();

    bool dataJaExiste = false;
    std::ifstream file_in(filename);
    std::string mensagem;
 
    while (!file_in.eof()){
        std::getline(file_in, mensagem);
        if(mensagem.size() != 0){
            if(mensagem.at(0)=='#' && mensagem.erase(0,2) == dataHoje){
                dataJaExiste=true;
            }
        }
    }
    
    if(!dataJaExiste){
        file_out << "# " << m.date.to_string() << std::endl;
    }
    file_out << "- " << m.time.to_string() << " " << m.content << std::endl;
    file_out.close();
    std::cout<< "Mensagem cadastrada com sucesso!"<<std::endl;
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


void Diary::aumentarCapacidade(){
	messages_capacity *= 2;
	Message* new_array = new Message[messages_capacity];
	for(size_t i=0; i<messages_size; i++){
		new_array[i] = messages[i];
	}
	delete[] messages;
	messages = new_array;
}


Message* Diary::search(const std::string& what){
	for(size_t i=0; i<messages_size; i++){
		if(messages[i].content.find(what,0) != std::string::npos){
			return &messages[i];
		}
	}
	return nullptr;
}


