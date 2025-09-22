#include "Model.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructeurs

// Test 3

Model::Model(const char* name, int power, Engine engine, float basePrice)
{
	this->name = new char[strlen(name) + 1];  
    strcpy(this->name, name);

    this->engine = engine;
    this->power = power;
    this->basePrice = basePrice;
}


Model::~Model()
{
	if (name!=nullptr)
	{
		delete[] name;
	}
}


// Autres Fonctions
// 2)
/*
void Model::setName(const char* modelname) 
{
	name = new char[strlen(modelname) + 1];
	strcpy(name, modelname);
}

void Model::setPower(int p)
{
	power = p;
}

void Model::setBasePrice(float prix)
{
	basePrice = prix;
}

void Model::setEngine(Engine e)
{
	engine = e;
}


const char* Model::getName()
{
	return name;
}

int Model::getPower()
{
	return power;
}

float Model::getBasePrice()
{
	return basePrice;
}

Engine Model::getEngine()
{
	return engine;
}
*/


// Test 4
Model::model1(const char* name, int power, Engine engine, float basePrice)
{
	this->name = new name[20];
	strcpy(this->name, name);
	this->power = power;
	this->engine = engine;
	this->basePrice = basePrice;
}

Model Model::model2(Model model1)
{
	strcpy(name, "2008 GT 1.2 PureTech 130 EAT8");
}


void Model::display()
{
	cout << "Nom : " << name << " Puissance : " << power << " Moteur : ";

	switch(engine)
	{
		case Petrol: cout << "Essence"; break;
		case Diesel: cout << "Diesel"; break;
		case Electric: cout << "Electrique"; break;
		case Hybrid: cout << "Hybride"; break;
	}

	cout << " Prix de Base : " << basePrice << " €" << endl;
}