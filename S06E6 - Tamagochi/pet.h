#ifndef PET_H
#define PET_H

#include <iostream>
#include <sstream>

using namespace std;

class Pet{

private:

string name;
int age{0};
int energyMax, hungryMax, cleanMax; 
int energy{0}, hungry{0}, clean{0};   
int diamond{0};
bool alive{true};

public:

Pet(string name, int energyMax, int hungryMax, int cleanMax);


string getName();

int getAge();

bool getalive();

int getclean();

int getenergyMax();

int getEnergy();

int getHungry();

int getClean();

int getDiamond();

void setName();

void setAge(int age);

void setalive(bool alive);

void setclean(int clean);

void setenergyMax(int energyMax);

void setEnergy(int energy);

void setHungry(int hungry);

void setDiamond(int diamond);

void setClean(int clean);

string toString();

void eatPet();

void playPet();

void toSleep();

void toClean();

};

#endif // PET_H