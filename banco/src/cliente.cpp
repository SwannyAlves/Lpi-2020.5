#include "Cliente.hpp"

int Cliente::qtdClientes;

Cliente::() {
    this -> qtdClientes += 1;
}

Cliente::~Cliente() {
}