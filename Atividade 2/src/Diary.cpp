#include "Diary.h"
#include "HoraDataAtual.h"
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
    

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    messages[messages_size] = m;
    messages_size++;
}

void Diary::addarq(const Message& message){
    if (messages_size >= messages_capacity) {
        newmessages = new Message[messages_capacity*2]; 
        for(int i = 0 ; i < messages_capacity ; i++){
            newmessages[i]= messages[i];
        }
        messages = newmessages;
    }
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



void Diary::read(){
    std::string line;
    std::ifstream file_input(filename);

    if (!file_input.is_open()){
        std::cout << "Arquivo não existente ou sem permissão de leitura. \n";
    }
    
    while (!file_input.eof()){
        getline(file_input, line);
    }
    file_input.close();
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

    	ler_linha = ler_linha.erase(0,2);
    	m.time.set_from_string(ler_linha.substr(0, 8));
    	ler_linha = ler_linha.erase(0, 8);
    	m.content = ler_linha.erase(0,1);
    	addarq(m);
  	}

}





