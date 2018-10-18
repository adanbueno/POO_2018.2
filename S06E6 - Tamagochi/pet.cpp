#include <iostream>
#include <sstream>
#include "pet.h"

using namespace std;

Pet::Pet(string name, int energyMax, int hungryMax, int cleanMax){
	this->name = name;
	this->age = age;
	this->alive = alive;
	this->clean = clean;
	this->diamond = diamond;
	this->energy = energyMax;
	this->hungry = hungryMax;
	this->clean = cleanMax;
	this->energyMax = energyMax;
	this->hungryMax = hungryMax;
	this->cleanMax = cleanMax;
}

string Pet::getName(){
	return this->name;
}

int Pet::getAge(){
	return this->age;
}

bool Pet::getalive(){
	return this->alive;
}

int Pet::getclean(){
	return this->clean;
}

int Pet::getenergyMax (){
	return this->energyMax ;
}

int Pet::getEnergy(){
	return this->energy;
}

int Pet::getHungry(){
	return this->hungry;
}

int Pet::getClean(){
	return this->clean;
}

int Pet::getDiamond(){
	return this->diamond;
}

void Pet::setName(){
	this->name = name;
}

void Pet::setAge(int age){
	this->age = age;
}

void Pet::setalive(bool alive){
	this->alive = alive;	
}

void Pet::setclean(int clean){
	this->clean = clean;
}

void Pet::setenergyMax(int energyMax ){
	this->energyMax = energyMax;
}

void Pet::setEnergy(int energy){
	this->energy = energy;
}

void Pet::setHungry(int hungry){
	this->hungry = hungry;
}

void Pet::setDiamond(int diamond){
	this->diamond = diamond;
}

void Pet::setClean(int clean){
	this->clean = clean;
}
  
string Pet::toString(){
	stringstream ss;
	cout << "Bora beber, cair e levantar" << endl;
	ss << "N:" << name << ", " 
	   << "E:" << energy << "/" << energyMax << ", "
	   << "H:" << hungry << "/" << hungryMax << ", "
	   << "C:" << clean  << "/" << cleanMax  << ", "
	   << "D:" << diamond << ", A:" << age;
	return ss.str();
}

void Pet::eatPet(){
	if(getEnergy() > 0 || getHungry() > 0 || getClean() > 0){
		this->energy--;
		this->clean -= 2;
		this->age++;
		this->hungry += 4;
	}	
	if(getHungry() >= 10)	
		this->hungry = 10;	

	else{
		if(getEnergy() < 0)		cout << "Seu PET morreu de Fraqueza!" << endl;
		if(getHungry() < 0)		cout << "Seu PET morreu de fome!" << endl;
		if(getClean() < 0)		cout << "Seu PET morreu de sujeira!" << endl;
	}
}

void Pet::playPet(){
	if(getEnergy() > 0 && getHungry() > 0 && getClean() > 0){
		this->energy -= 2;	//Diminui 2 na energia
		this->hungry--;		// Diminui 1 na fome
		this->clean -= 3;	// Diminui 3 da limpeza
		this->age++;		// Aumenta 1 na idade
		this->diamond++;	// Aumenta 1 no diamante
	}
		if(getEnergy() <= 0){
			setEnergy(0);
			cout << "Seu PET morreu de Fraqueza!" << endl;
		}		
		if(getHungry() <= 0){
			setHungry(0);
			cout << "Seu PET morreu de fome!" << endl;
		}		
		if(getClean() <= 0){
			setClean(0);
			cout << "Seu PET morreu de sujeira!" << endl;
		}		

}

void Pet::toSleep(){
	int turno;
	turno = getenergyMax() - getEnergy();
	if(getEnergy() > 0 && getalive() == true && turno >= 5){
		this->hungry--;
		this->energy = energyMax;
		this->age += turno;
	}
		
}

void Pet::toClean(){
	if(getEnergy() > 0 && getHungry() > 0 && getClean() > 0){
		this->energy -= 3;
		this->hungry--;
		this->age += 2;
		this->clean = cleanMax;
	}
		if(getEnergy() <= 0){
			setEnergy(0);
			cout << "Seu PET morreu de Fraqueza!" << endl;
		}		
		if(getHungry() <= 0){
			setHungry(0);
			cout << "Seu PET morreu de fome!" << endl;
		}		
		if(getClean() <= 0){
			setClean(0);
			cout << "Seu PET morreu de sujeira!" << endl;
		}		
	
}