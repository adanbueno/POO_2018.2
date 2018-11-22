#ifndef AGENDA
#define AGENDA

#include <string.h>
#include <sstream>
#include <vector>
#include "contato.h"
#include "fone.h"

using namespace std;

class Agenda{
private:

public:
	vector<Contato*> contacts;
	int size{0};

	Agenda();
	bool toInsert(string id);
	void toLogin(string id);
	void toShowAll();
	void toRename(string newId, int id);
	Contato* toRemove(string id);

};

#endif // AGENDA