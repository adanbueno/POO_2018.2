#ifndef CONTATO
#define CONTATO

#include <string.h>
#include <sstream>
#include <vector>
#include "fone.h"

using namespace std;

class Contato{
private:

public:
	vector<Fone*> fones;
	string oper;
	string id;

	Contato(string id);
	void toInsert(string oper, string fone);
	Fone *toRemove(int id);
	void showAll();
};

#endif // CONTATO