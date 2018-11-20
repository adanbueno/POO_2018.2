#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include <vector>
#include "sistema.h"
#include "usuario.h"
using namespace std;

struct Controll{
    vector<Usuario> usuarios;
    vector<Nota> notas;

    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        try{
        Usuario * usuario = nullptr;
            cout << "Digite help ou comando: ";
            if(op == "help"){
                cout << "addUser $username $password" << endl
                    << "updatePass $oldpass $newpass" << endl
                    << "addNote $titulo $textao" << endl
                    << "rmNote $titulo" << endl
                    << "users" << endl
                    << "login $username $password" << endl
                    << "logout" << endl
                    << "show" << endl;
            }
            if(op == "users"){
                cout << "Usuarios: [ ";
                for(auto st : sistema.getUsernames())
                    cout << st << " ";
                cout << "]"  << endl;
            }
            if(op == "addUser"){
                string name, pass;
                in << name << pass;
                if(sistema.addUser(name, pass))
                    cout << "sucesso" << endl;
                else
                    cout << "username duplicado" << endl;
            }

            if(op == "login"){
                string name, pass;
                in << name << pass;
                usuario = sistema.getUser(name, pass);
                if(usuario == nullptr)
                    cout << "erro de login" << endl;
                else
                    cout << "sucesso" << endl;
            }
            if(op == "show"){
                if(usuario == nullptr)
                    cout << "ninguem logado" << endl;
                else
                    cout << usuario->toString() << endl;
            }
            if(op == "rmNote"){
                string titulo;
                in << titulo;
                if(usuario == nullptr)
                    cout << "ninguem logado" << endl;
                else
                    cout << (usuario->rmNota(titulo)? "ok":"falhou") << endl;
            }

            if(op == "logout"){
                if(usuario != nullptr){
                    usuario = nullptr;
                    cout << "logout efetuado" << endl;
                }else{
                    cout << "ninguem logado" << endl;
                }

            }
            if(op == "updatePass"){
                string old, newp;
                in << old << newp;
                if(usuario == nullptr)
                    cout << "ninguem logado" << endl;
                else
                    cout << (usuario->updatePass(old, newp)? "ok" : "senha invalida") << endl;
            }
            if(op == "addNote"){
                string titulo, texto;
                in << titulo;
                getline(cin, texto);
                if(usuario)
                    cout << (usuario->addNota(Nota(titulo, texto)) ? "nota adicionada" : "titulo duplicado") << endl;
                else
                    cout << "usuario nao logado" << endl;

            }
        }catch(string erro){
            cout << "\033[32m" << "   " << erro << "\033[39m" << endl;
        }
        return out.str();
    }


    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end"){
                break;
            }
            cout << "\033[35m" << line << "\033[39m" << endl;
            cout << funcoes(line) << endl;
            
        }
    }
};

#endif