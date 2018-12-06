#include "patient.h"
#include "doctor.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Patient::Patient(string name = "", string diag = "") : User(name), diag(diag){}
Patient::~Patient(){}

string Patient::readMsg(){
    stringstream out;
    for(size_t i = 0; i < inbox.size(); i++){
        out << inbox[i].toString();
    }
    return out.str();
}

string Patient::getDocs(size_t i = 0){
    if(i == d_list.size())
        return "";
    return d_list[i]->name + " " + getDocs(i+1);
}

string Patient::toString(){
    return "Pat: " + this->name + ":" + this->diag + "\tDocs: [" + getDocs() + "]" ;
}

void Patient::sendMsg(string to, string text){
    for(size_t i = 0; i < d_list.size(); i++){
        if(d_list[i]->name == to)
            d_list[i]->inbox.push_back(Msg(to, text));
    }
}

void Patient::sendMsg(string from, string to, string text){
    for(size_t i = 0; i < d_list.size(); i++){
        if(d_list[i]->name == to){
            d_list[i]->inbox.push_back(Msg(from, text));
            return;
        }
    }
    throw "fail: Eles nao se conhecem";
}

void Patient::tie(void * d){
    Doctor * doc = (Doctor *)d;
    this->d_list.push_back(doc);
}