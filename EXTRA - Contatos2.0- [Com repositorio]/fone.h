#ifndef FONE
#define FONE

#include <string.h>
#include <sstream>

using namespace std;

class Fone{
private:
	string fone;
	string data;
	string oper;
public:
	
	Fone(string oper, string fone);

	string toString();

	string getFone();

	string getData();

	string getOper();

	void setFone(string fone);

	void setData(string data);

	void setOper(string oper);
};

#endif // FONE