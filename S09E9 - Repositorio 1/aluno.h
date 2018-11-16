#ifndef STUDENT
#define STUDENT

#include <iostream>
using namespace std;

class Student{
private:
    string name;
    string registration;
    string course;
public:
    Student(string registration = "", string course = "", string name = ""){
        this->registration = registration;
        this->course = course;
        this->name = name;
    }
    string toString(){
        return registration + ":" + course + ":" + name;

    }
};

#endif
