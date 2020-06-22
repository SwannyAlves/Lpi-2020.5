#ifndef mensagem_h_aula5
#define mensagem_h_aula5

#include <string>

struct comando //comando que diz se é add ou list
{
    int argce;
    std::string argve;
};

struct horario { //horario que a mensagem foi cadastrada
    int hora;
    int minuto;
    int segundo;
};

struct data // dia que a mensagem foi cadastrada 
{
    int dia;
    int mes; 
    int ano;
};


struct mensagem { // cadastrar 
    data date;
    horario time;
    std::string couteudo;

    bool compararDatas(const data &outra_data); //verificar uma data para ver se repete
};

#endif

