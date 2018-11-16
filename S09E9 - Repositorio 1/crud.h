#ifndef CRUD
#define CRUD

#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T >
struct Repository{
    map <string, T > things;

    bool exist(string key){
    return things.find(key) != things.end();
    }

    void add(string key, T element){
        if(!exist(key)){
        things[key] = element;
        }
        else{
            throw "Fail: " + key + "already exists";
        }
    }

    void rm(string key){
        if(!exist(key)){
            throw "Fail: " + key + "Not exist";
        }
        things.erase(key);
    }

    string get(string key){
        auto it = things.find(key);
        if(it != things.end()){
            return "  " + it->second.toString() + "\n";
        }
        else{
            throw "Fail: " + key + "Not exist";
        }
    }

    string show(){
    stringstream ss;
        for(auto par : things){
        ss << "  " << par.second.toString() << endl;
        }
        return ss.str();
    }
};
#endif