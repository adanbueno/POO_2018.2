#ifndef _DOCTOR_H_
#define _DOCTOR_H_
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "patient.h"

using namespace std;

class Doctor : public User{
public:
    string spec;
    vector<Patient*> p_list;
    Doctor(string, string);
    virtual ~Doctor();
    string readMsg();
    void sendMsg(string, string);
    void sendMsg(string, string, string);
    string getPats(size_t);
    string toString();
    virtual void tie(void *);

};

#endif //_DOCTOR_H_