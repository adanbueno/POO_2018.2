#include "doctor.h"

Doctor::Doctor(string name = "", string spec = "") : User(name),spec(spec){}

Doctor::~Doctor(){}

string Doctor::readMsg(){
    stringstream out;
    for(size_t i = 0; i < inbox.size(); i++){
        out << inbox[i].toString();
    }
    return out.str();
}

void Doctor::sendMsg(string to, string text){
    for(size_t i = 0; i < p_list.size(); i++){
        if(p_list[i]->name == to)
            p_list[i]->inbox.push_back(Msg(to, text));
    }
}

void Doctor::sendMsg(string from, string to, string text){
    for(size_t i = 0; i < p_list.size(); i++){
        if(p_list[i]->name == to)
            p_list[i]->inbox.push_back(Msg(from, text));
    }
}

string Doctor::getPats(size_t i = 0){
    if(i == p_list.size())
        return "";
    return p_list[i]->name + " " + getPats(i+1);
}

string Doctor::toString(){
    return "Doc: " + this->name + ":" + this->spec + "\tPats: [" + getPats() + "]" ;
}

void Doctor::tie(void * p){
    Patient * pat = (Patient *) p;
    stringstream pats(getPats());
    string aux;
    while(pats >> aux){
        if(pat->name == aux)
            throw "fail: Paciente ja pertencente a esta lista";
    }
    for(size_t i = 0; i < pat->d_list.size(); i++){
        if(pat->d_list[i]->spec == this->spec)
            throw "fail: ja existe outro medico com esta especialidade";
    }
    pat->tie(this);
    p_list.push_back(pat);
}