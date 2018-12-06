#ifndef _PATIENT_H_
#define _PATIENT_H_
#include "user.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Doctor;

class Patient : public User{
public:
    string diag;
    vector<Doctor*> d_list;
    Patient(string, string);
    virtual ~Patient();
    virtual string readMsg();
    void sendMsg(string, string);
    void sendMsg(string, string, string);
    string getDocs(size_t);
    string toString();
    virtual void tie(void *);

friend class Doctor;
};

#endif //_PATIENT_H_