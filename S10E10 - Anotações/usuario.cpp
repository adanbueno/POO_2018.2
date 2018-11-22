#include <iostream>
#include <sstream>
#include "nota.h"
#include "usuario.h"

using namespace std;

Usuario::Usuario(string username = "", string password = ""){
    this->username = username;
    this->password = password;
}

string Usuario::getUsername(){
    return username;
}

bool Usuario::updatePass(string  oldpass, string newpass){
    if(this->password == oldpass){
        this->password = newpass;
        return true;
    }
    return false;
}

bool Usuario::addNota(Nota nota){
    for(auto elemento : notas){
        if(elemento.getTitulo() == nota.getTitulo())
            return false;
    }
    notas.push_back(nota);
    return true;
}

bool Usuario::rmNota(string titulo){
    for(int i = 0; i < (int) this->notas.size(); i++){
        if(notas[i].getTitulo() == titulo){
            notas.erase(notas.begin() + i);
            return true;
        }

    }
    return false;
}

bool Usuario::checkPassword(string password){
    return this->password == password;
}

string Usuario::toString(){
    stringstream ss;
    ss << username << endl;
    for(auto nota : notas)
        ss << "[" << nota.getTitulo() << "; " << nota.getTexto() << "]" << endl;
    return ss.str();
}