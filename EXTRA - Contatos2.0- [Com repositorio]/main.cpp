#include <iostream>
#include "contato.h"
#include "fone.h"
#include "agenda.h"

using namespace std;

int main(){

string id, op;

Agenda agenda = Agenda();

while(1){
	cin >> op;

	if(op == "init"){
		cin >> id;
		if(agenda.toInsert(id))	cout << "sucess" << endl;
		else cout << "fail" << endl;
	} else if(op == "login"){
		cin >> id;
		agenda.toLogin(id);
	} else if(op == "remove"){
		cin >> id;
		Contato *c1 = agenda.toRemove(id);
		delete c1;
	}
}
	return 0;
}