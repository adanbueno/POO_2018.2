#ifndef USUARIO 
#define USUARIO

#include <iostream>
#include <vector>
#include <sstream>
#include "nota.h"

using namespace std;

class Usuario{
    string username;
    string password;
    vector<Nota> notas;
public:

    Usuario (string username = "", string password = ""){
        this->username = username;
        this->password = password;
    }

    string getUsername(){
        return username;
    }

    bool updatePass(string  oldpass, string newpass){
        if(this->password == oldpass){
            this->password = newpass;
            return true;
        }
        return false;
    }

    bool addNota(Nota nota){
        for(auto elemento : notas){
            if(elemento.getTitulo() == nota.getTitulo())
                return false;
        }
        notas.push_back(nota);
        return true;
    }

    bool rmNota(string titulo){
        for(int i = 0; i < (int) this->notas.size(); i++){
            if(notas[i].getTitulo() == titulo){
                notas.erase(notas.begin() + i);
                return true;
            }

        }
        return false;
    }

    bool checkPassword(string password){
        return this->password == password;
    }

    string toString(){
        stringstream ss;
        ss << username << endl;
        for(auto nota : notas)
            ss << "[" << nota.getTitulo() << "; " << nota.getTexto() << "]" << endl;
        return ss.str();
    }
};

#endif