#include "Model.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructeurs

// Test 3
/*
// Constructeur d'initialisation
Model::Model(const char* name, int power, Engine engine, float basePrice)
{
	this->name = new char[strlen(name) + 1];  
    strcpy(this->name, name);

    this->engine = engine;
    this->power = power;
    this->basePrice = basePrice;

    //name = new char[20];
    //power = 0;
    //engine=Petrol:
	//basePrice = 0;
}

*/



// Constructeur de copie
Model::Model(const char* nom, int puissance, Engine moteur, float prix)
{
	// setName(nom);
	// setPower(puissance);
	// setEngine(moteur);
	// setBasePrice(prix);
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
	power = puissance;
	engine = moteur;
	basePrice = prix;
}

Model::Model(Model &source)
{
	name = new char[20];
	setName(source.getName());
	//setName(source.name);
	power = source.power;
	engine = source.engine;
	basePrice = source.basePrice;
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

void Model::setName(const char* modelname) 
{
	if (name!=nullptr)
	{
		delete[] name;
	}
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

char* Model::getName()
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