#include "Model.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

using namespace carconfig;

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


namespace carconfig
{
	istream& operator>>(istream& is, Model& m)
	{
		char temp[100];
		float prix;
		int puissance;
		int choix;
		Engine moteur;

		cout << "Entrez le nom du Modèle: " << endl;
		is >> setw(100) >> temp;


		cout << "Entrez la puissance du Modèle (chevaux): " << endl;
		is >> puissance;
		while (puissance < 0)
		{
			cout << "Pas de puissance négative!" << endl;
			is >> puissance;
		}
		cout << "Entrez le prix: " << endl;
		is >> prix;
		while (prix < 0)
		{
			cout << "Pas de prix négative!" << endl;
			is >> prix;
		}
		cout << "Entrez le moteur: \t0) Essence \t1) Diesel \t2)Electrique \t3)Hybride" << endl;
		is >> choix;
		while (choix < 0 || choix > 3)
		{
			cout << "Entre 0 et 3!" << endl;
			is >> choix;
		}

		switch(choix)
		{
			case 0: moteur = Petrol; break;
			case 1: moteur = Diesel; break;
			case 2: moteur = Electric; break;
			case 3: moteur = Hybrid; break;
		}


		m.setName(temp);
		m.setBasePrice(prix);
		m.setEngine(moteur);
		m.setPower(puissance);

		return is;
	}

	ostream& operator<<(ostream& os, const Model& m)
	{
		os << "Nom du modèle : " << m.getName() << endl
	       << "Puissance : " << m.getPower() << " ch" << endl
	       << "Prix de base : " << m.getBasePrice() << " €" << endl
	       << "Moteur : ";

	    switch (m.getEngine())
	    {
	        case Petrol: os << "Essence"; break;
	        case Diesel: os << "Diesel"; break;
	        case Electric: os << "Électrique"; break;
	        case Hybrid: os << "Hybride"; break;
	        default: os << "Inconnu"; break;
	    }

	    os << endl;	

		return os;
	}
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