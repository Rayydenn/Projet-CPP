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

float Model::getbasePrice()
{
	return basePrice;
}


void Model::display()
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