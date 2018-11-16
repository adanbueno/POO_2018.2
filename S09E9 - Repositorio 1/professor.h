#ifndef TEACHER
#define TEACHER

#include <iostream>
//#include "crud.h"

class Teacher{
private:
    string name;
    string siape;
public:
    Teacher(string name = "", string siape = ""){
        this->name = name;
        this->siape = siape;
    }
    string toString(){
        return siape + ":" + name;

    }
};

#endif