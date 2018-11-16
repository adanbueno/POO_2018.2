#ifndef DISCIPLINA
#define DISCIPLINA

#include <iostream>
using namespace std;

class Subject{
private:
    string code;
    string name;
public:
    Subject(string code = " ", string name = " "){
        this->code = code;
        this->name = name;
    }

    string toString(){
        return code + ":" + name;
    }
};

#endif