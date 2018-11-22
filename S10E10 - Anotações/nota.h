#ifndef NOTA
#define NOTA

#include <iostream>

using namespace std;

class Nota{
private:
	string texto;
	string titulo;
public:

	Nota(string texto, string titulo);

	string getTitulo();

    string getTexto();

    void setTitulo(string titulo);

    void setTexto(string texto);
};

#endif // NOTA