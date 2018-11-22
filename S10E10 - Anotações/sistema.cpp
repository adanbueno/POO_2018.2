#include <iostream>
#include <sstream>
#include "nota.h"
#include "usuario.h"
#include "sistema.h"

using namespace std;

Sistema::Sistema(){
}

//não pode ter dois usernames iguais
bool Sistema::addUser(string username, string password){
    for(auto usuario : usuarios)
        if(usuario.getUsername() == username)
            return false;
    usuarios.push_back(Usuario(username, password));
    return true;
}

Usuario * Sistema::getUser(string username, string password){
    for(auto& usuario : usuarios)
        if((usuario.getUsername() == username) && (usuario.checkPassword(password)))
            return &usuario;
    return nullptr;
}

vector<string> Sistema::getUsernames(){
    vector<string> names;
    for(auto& user : usuarios)
        names.push_back(user.getUsername());
    return names;
}

void rep_Anotacoes(Sistema& sistema){

string op = "";

Usuario * usuario = nullptr;

while(op != "exit"){

cout << "Digite help ou comando: ";
cin >> op;
if(op == "help"){
    
    cout << "addUser $username $password" << endl
         << "users" << endl
         << "login $username $password" << endl
         << "logout" << endl
         << "addNote $titulo $texto" << endl
         << "rmNote $titulo" << endl
         << "updatePass $oldpasspass $newpassass" << endl
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
    cin >> name >> pass;
    if(sistema.addUser(name, pass))
        cout << "sucess!" << endl;
    else
        cout << "Nome de usuario duplicado" << endl;
}

if(op == "login"){
    string name, pass;
    cin >> name >> pass;
    usuario = sistema.getUser(name, pass);
    if(usuario == nullptr)
        cout << "erro no login" << endl;
    else
        cout << "sucess" << endl;
}

if(op == "show"){
    if(usuario == nullptr)
        cout << "nao ha ninguem logado" << endl;
    else
        cout << usuario->toString() << endl;
}

if(op == "rmNote"){
    string titulo;
    cin >> titulo;
    if(usuario == nullptr)
        cout << "nao ha ninguem logado" << endl;
    else
        cout << (usuario->rmNota(titulo)? "ok":"deu ruim") << endl;
}

if(op == "logout"){
    if(usuario != nullptr){
        usuario = nullptr;
        cout << "logout feito" << endl;
    }else{
        cout << "nao ha ninguem logado" << endl;
    }

}

if(op == "updatePass"){
    string oldpass, newpass;
    cin >> oldpass >> newpass;
    if(usuario == nullptr)
        cout << "nao ha ninguem logado" << endl;
    else
        cout << (usuario->updatePass(oldpass, newpass)? "ok" : "senha invalida") << endl;
}

if(op == "addNote"){
    string titulo, texto;
    cin >> titulo;
    getline(cin, texto);
    if(usuario)
        cout << (usuario->addNota(Nota(titulo, texto)) ? "nota adicionada" : "titulo duplicado") << endl;
    else
        cout << "usuario nao esta logado" << endl;

        }
    }
}

void controller(Sistema &sistema){
    sistema.addUser("Adan", "Bueno");
    sistema.addUser("morena", "xaninha");
    Usuario * adan = sistema.getUser("Adan", "Bueno");
    adan->addNota(Nota("ligar", "morena"));
    adan->addNota(Nota("ouvir", "ze neto"));
    adan->addNota(Nota("chorar", "arquitetura me fudeu"));
    Usuario * morena = sistema.getUser("morena", "xaninha");
    morena->addNota(Nota("af", "arq"));
    morena->addNota(Nota("saudades", "IRA 8"));
    morena->addNota(Nota("Opa", "saudades"));
}