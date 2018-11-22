#include <iostream>
#include "nota.h"

using namespace std;

Nota::Nota(string texto = "", string titulo = ""){
    this->titulo = titulo;
    this->texto = texto;
}

string Nota::getTitulo(){
    return titulo;
}

string Nota::getTexto(){
    return texto;
}

void Nota::setTitulo(string titulo){
    this->titulo = titulo;
}

void Nota::setTexto(string texto){
    this->texto = texto;
}