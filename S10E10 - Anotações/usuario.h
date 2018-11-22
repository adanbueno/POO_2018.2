#ifndef USUARIO
#define USUARIO

#include <iostream>
#include <vector>
#include "nota.h"

using namespace std;

class Usuario{
private:
	vector<Nota> notas;
	string username;
    string password;
public:

	Usuario (string username, string password);

    string getUsername();

    bool updatePass(string  oldpass, string newpass);

    bool addNota(Nota nota);

    bool rmNota(string titulo);

    bool checkPassword(string password);

    string toString();
};

#endif // USUARIO