#include <iostream>
#include "agenda.h"
#include "contato.h"
#include "fone.h"

using namespace std;

Agenda::Agenda(){
	this->size = 0;
}

bool Agenda::toInsert(string id){

    for(int i = 0; i < contacts.size(); i++){
        if(contacts[i]->id == id){
            cout << "false: id nao valido." << endl;
            return false;
        }
    }

    Contato *c1 = new Contato(id);
    contacts.push_back(c1);

    return true;
}

void Agenda::toLogin(string id){
    int id_vector = -1;

    for(int i = 0; i < contacts.size(); i++){
        if(id == contacts[i]->id){
            id_vector = i;
            break;
        }
    }
    if(id_vector == -1){
        cout << "fail: contato nao label." << endl;
    }else{
        repAgenda(id_vector);
    }
}

void Agenda::toShowAll(){
	cout << "contacts"<<endl;
    for(int i = 0; i < contacts.size(); i++){
        if(contacts[i] != nullptr){
            cout << endl <<"["<<contacts[i]->id <<"]"<< endl;
            for(int j = 0; j < contacts[i]->fones.size(); j++){
                if(contacts[i]->fones[j] != nullptr){
                    cout <<"["<<contacts[i]->fones[j]->getData() <<"]"<< endl;
                }
            }
        }
	}
}

Contato* Agenda::toRemove(string id){
	for(int i = 0; i < contacts.size(); i++){
        if(id == contacts[i]->id){
            auto *pass = contacts[i];
            contacts[i] = nullptr;
            return pass;
        }
    }
return nullptr;

}

void Agenda::toRename(string newId, int _id){
    int label = 0, i;
    for(i = 0; i < contacts.size(); i++){
        if(newId == contacts[i]->id){
            label = 1;
            cout << "fail: id invalido" << endl;
            break;
        }
    }
    if(label == 0){
        contacts[_id]->id = newId;
        cout << "sucess" << endl;
    }
}

void Agenda::repAgenda(int id_vect){
    string op, number, id;
    string oper;
    string allow_num = "0123456789()";
    int label, num;

    while(1){
        cin >> op;
        if(op == "add"){
            label = 1;
            cin >> oper;
            cin >> number;
            for(char x : number){
                if(allow_num.find(x) == string::npos){
                    label = 0;
                    break;
                }
            }

            if(label)   contacts[id_vect]->toInsert(oper, number);
            else        cout << "fail: numero invalido" << endl;

        } else if(op == "show"){
            contacts[id_vect]->showAll();
        } else if(op == "rm"){
            cin >> num;
            Fone *f1 = contacts[id_vect]->toRemove(num);
            delete f1;
        } else if(op == "rename"){
            cin >> id;
            toRename(id, id_vect);
        }
    }
}