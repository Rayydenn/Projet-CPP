#include "Model.h"

using namespace carconfig;

Model::Model()
{
	Name = "";
	Power = 0;
	basePrice = 0.0f;
	engine = Petrol;
}

Model::Model(const string& n, const int p, const Engine e, const float bp)
{
	Name = n;
	Power = p;
	basePrice = bp;
	engine = e;
}

Model::Model(const Model &source)
{
	Name = source.Name;
	Power = source.Power;
	basePrice = source.basePrice;
	engine = source.engine;
}


void Model::setName(const string& n)
{
	Name = n;
}

void Model::setPower(const int p)
{
	Power = p;
}

void Model::setbasePrice(const float bp)
{
	basePrice = bp;
}

void Model::setEngine(const Engine e)
{
	engine = e;
}

float Model::getbasePrice() const
{
	return basePrice;
}

string Model::getName() const
{
	return Name;
}

int Model::getPower() const
{
	return Power;
}

Engine Model::getEngine() const
{
	return engine;
}

namespace carconfig
{
	istream& operator>>(istream& is, Model& m)
	{
		string nom;
		float prix;
		int puissance;
		int choix;
		Engine moteur;

		cout << "Entrez le nom du Modèle: " << endl;
		getline(is, nom);
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


		m.setName(nom);
		m.setbasePrice(prix);
		m.setEngine(moteur);
		m.setPower(puissance);

	return is;
	}

	ostream& operator<<(ostream& os, const Model& m)
	{
		os << "Nom du modèle : " << m.getName() << endl
	       << "Puissance : " << m.getPower() << " ch" << endl
	       << "Prix de base : " << m.getbasePrice() << " €" << endl
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



void Model::display() const
{
	cout << "Nom: " << Name << endl << "Puissance: " << Power << endl << "Prix: " << basePrice << endl << "Moteur: ";

	switch(engine)
	{
		case Petrol: cout << "Essence" << endl; break;
		case Diesel: cout << "Diesel" << endl; break;
		case Electric: cout << "Electrique" << endl; break;
		case Hybrid: cout << "Hybride" << endl; break;
	}
}