#include "Model.h"
#include <cstring>

using namespace std;

Model::Model() {
    name = "";
    power = 0;
    basePrice = 0.0f;
    engine = Petrol;
}

Model::Model(const string& nom, int puissance, Engine moteur, float prix)
{
	power = puissance;
	basePrice = prix;
	engine = moteur;
	name = nom;
}

void Model::display()
{
	cout << "Nom: " << name << endl 
	<< "Puissance: " << power << endl 
	<< "Prix: " << basePrice << " €" << endl;

	switch(engine)
	{
		case Petrol: cout << "Essence" << endl; break;
		case Diesel: cout << "Diesel" << endl; break;
		case Electric: cout << "Electrique" << endl; break;
		case Hybrid: cout << "Hybride" << endl; break;
	}
}