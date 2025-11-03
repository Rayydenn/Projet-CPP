#include "Model.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructeurs
Model::Model()
{
	name = new char[20];
	setName(name);
	setPower(0);
	setEngine(Engine::Petrol);
	setBasePrice(0.0);
}

Model::Model(const char* n, const int p, const Engine e, const float prix)
{
	name = new char[20];
	setName(n);
	setPower(p);
	setEngine(e);
	setBasePrice(prix);
}
Model::Model(const Model &source)
{
	name = new char[20];
	setName(source.getName());
	setPower(source.getPower());
	setEngine(source.getEngine());
	setBasePrice(source.getBasePrice());
}

Model::~Model()
{
	delete[] name;
}

// SETTERS / GETTERS

void Model::setName(const char* n) 
{
	if (name != nullptr)
		delete[] name;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
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

char* Model::getName() const
{
	return name;
}

int Model::getPower() const
{
	return power;
}

float Model::getBasePrice() const
{
	return basePrice;
}

Engine Model::getEngine() const
{
	return engine;
}

// DISPLAY

void Model::display() const
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