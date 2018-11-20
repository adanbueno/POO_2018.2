#ifndef NOTA
#define NOTA

#include <iostream>
#include <vector>
#include <sstream>
#include "controller.h"
#include "sistema.h"
#include "usuario.h"
#include "nota.h"
using namespace std;

class Nota{
    string titulo;
    string texto;
public:
    Nota(string titulo = " ", string texto = " "){
        this->titulo = titulo;
        this->texto = texto;
    }

    string getTitulo(){
        return titulo;
    }
    string getTexto(){
        return texto;
    }

    void setTitulo(string titulo){
        this->titulo = titulo;
    }

    void setTexto(string texto){
        this->texto = texto;
    }

};


#endif