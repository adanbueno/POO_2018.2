#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <sstream>
#include "crud.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
using namespace std;

struct Controll{
    Repository < Student > students;
    Repository < Teacher > teachers;
    Repository < Subject > subjects;

    string funcoes(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        try{
            if(op == "help"){
                out << "  end;" << endl
                    << "  addAlu(registration, course, name);" << endl
                    << "  addPro(name, siape);" << endl
                    << "  addDis(código, name);" << endl
                    << "  showAlu;" << endl
                    << "  showPro;" << endl
                    << "  showDis;" << endl
                    << "  getAlu(registration);" << endl
                    << "  getPro(siape);" << endl
                    << "  getDis(code);" << endl
                    << "  rmAlu(registration);" << endl
                    << "  rmPro(siape);" << endl
                    << "  rmDis(code);" << endl;
            }else if(op == "addAlu"){
                string registration, course, name;
                in >> registration >> course;
                getline(in, name);
                students.add(registration, Student(registration, course, name));
            }else if(op == "addPro"){
                string name, siape;
                in >> siape;
                getline(in, name);
                teachers.add(siape, Teacher(name, siape));
            }else if(op == "addDis"){
                string code, name;
                in >> code;
                getline(in, name);
                subjects.add(code, Subject(code, name));
            }else if(op == "showAlu"){
                out << students.show();
            }else if(op == "showPro"){
                out << teachers.show();
            }else if(op == "showDis"){
                out << subjects.show();
            }else if(op == "getAlu"){
                string key;
                in >> key;
                out << students.get(key);
            }else if(op == "getPro"){
                string key;
                in >> key;
                out << teachers.get(key);
            }else if(op == "getDis"){
                string key;
                in >> key;
                out << subjects.get(key);
            }else if(op == "rmAlu"){
                string key;
                in >> key;
                students.rm(key);
            }else if(op == "rmPro"){
                string key;
                in >> key;
                teachers.rm(key);
            }else if(op == "rmDis"){
                string key;
                in >> key;
                subjects.rm(key);
            }
        }catch(string erro){
            cout << "\033[32m" << "   " << erro << "\033[39m" << endl;
        }
        
        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            if(line == "end"){
                break;
            }
            cout << "\033[35m" << line << "\033[39m" << endl;
            cout << funcoes(line) << endl;
            
        }
    }

};


#endif