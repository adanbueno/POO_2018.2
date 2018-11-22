#include "fone.h"
#include "contato.h"

using namespace std;

Fone::Fone(string oper = "", string fone = ""){
	stringstream ss;
	this->oper = oper;
	this->fone = fone;
	ss << oper << ":" << fone;
	this->data = ss.str();
}

string Fone::toString(){
	stringstream ss;
	ss << data;
	return ss.str();
}

string Fone::getFone(){
	return this->fone;
}

string Fone::getData(){
	return this->data;
}

string Fone::getOper(){
	return this->oper;
}

void Fone::setFone(string fone){
	this->fone = fone;
}

void Fone::setData(string data){
	this->data = data;
}

void Fone::setOper(string oper){
	this->oper = oper;
}