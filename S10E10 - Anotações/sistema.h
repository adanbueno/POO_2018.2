#ifndef SISTEMA
#define SISTEMA
#include <iostream>
#include <vector>
#include <sstream>
#include "usuario.h"


using namespace std;

class Sistema{
    vector<Usuario> usuarios;
public:
    Sistema(){
    }

    //não pode ter dois usernames iguais
    bool addUser(string username, string password){
        for(auto usuario : usuarios)
            if(usuario.getUsername() == username)
                return false;
        usuarios.push_back(Usuario(username, password));
        return true;
    }

    Usuario * getUser(string username, string password){
        for(auto& usuario : usuarios)
            if((usuario.getUsername() == username) && (usuario.checkPassword(password)))
                return &usuario;
        return nullptr;
    }
    vector<string> getUsernames(){
        vector<string> names;
        for(auto& user : usuarios)
            names.push_back(user.getUsername());
        return names;
    }
};


#endif