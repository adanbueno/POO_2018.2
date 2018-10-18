#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Fone{
    string id;   //atributos
    string fone;
    Fone(string id = "", string fone = ""): //Construindo um construtor que pega id e fone nulos
        id(id), fone(fone)                  //id e fone atributo recebe id e fone paramentro 
    {
    }

    static bool validar(string fone){
        string valid = "0123456789().";
        for(auto c: fone)
            if(valid.find(c) == string::npos) //nao encontrou
                return false;
        return true;
    }
    string toString(){
        stringstream ss;
        ss << "[" << id << ":" << fone << "]"; //adicionando a operadora e o telefone
        return ss.str();
    }
};

class Contato{
private:
    string id;
    vector<Fone> fones;
public:
    Contato(string id = "LULA LADRAO"):
        id(id)
    {
    }

    void add(Fone fone){
        for(auto telefone : fones)
            if(telefone.id == fone.id){
                cout << "failure: id duplicado";
                return;
            }
        fones.push_back(fone);
    }

    void rm(string foneId){
        for(int i = 0; i < (int) fones.size(); i++)
            if(fones[i].id == foneId){
                fones.erase(fones.begin() + i);
            }
    }

    string toString(){
        stringstream ss;
        ss << id << "=>";
        for(auto fone : fones)
            ss << fone.toString();
        return ss.str();
    }
};

struct Controller{
    Contato cont;

    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help")
            out << "\nSHOW; \nINIT: \nNAME; \nADD: \nID and FONE; \nUPDATE; \nREMOVE; \nEND";
        else if(op == "init"){
            string nome;
            in >> nome;
            cont = Contato(nome);
            out << "success";
        }else if(op == "show"){
            out << cont.toString();
        }else if(op == "add"){
            string id, fone;
            in >> id >> fone;
            cont.add(Fone(id, fone));
        }else if(op == "rm"){
            string id;
            in >> id;
            cont.rm(id);
        }else if(op == "update"){
            string nome;
            in >> nome;
            cont = Contato(nome);
            string fone_serial;
            while(in >> fone_serial){
                stringstream ss(fone_serial);
                string id, fone;
                getline(ss, id, ':');
                getline(ss, fone);
                if(Fone::validar(fone))
                    cont.add(Fone(id, fone));
            }
        }
        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end")
                return;
            cout << line << endl;
            cout << "  " << shell(line) << endl;
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
    return 0;
}
