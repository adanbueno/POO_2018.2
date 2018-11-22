#include <iostream>
#include "fone.h"
#include "contato.h"

using namespace std;

Contato::Contato(string id){
	this->id = id;
}

void Contato::toInsert(string oper, string fone){
	Fone *f1 = new Fone(oper, fone);
	fones.push_back(f1);
} 

Fone *Contato::toRemove(int id){
	if(id < fones.size()){
		int j = -1;
		for(int i = 0; i < fones.size(); i++){
			if(fones[i] != nullptr)	j++;
			if(j == id){
				auto *pass = fones[i];
				fones[i] = nullptr;
				return pass;
			}
		}
	}
	return nullptr;
}

void Contato::showAll(){
	int id = 0;
	for(int i = 0; i < fones.size(); i++){
		if(fones[i] != nullptr){
			cout << id << " - " << fones[i]->toString() << endl;
			id++;
		}
	}
}