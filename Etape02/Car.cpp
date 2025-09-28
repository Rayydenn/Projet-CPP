#include <iostream>
#include "Car.h"
#include "Model.h"
#include <cstring>

void Car::setName(nom)
{
	if (name!=nullptr)
		delete[] name;
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
}

void Car::setModel(modele)
{
	
}


void Car::display()
{
	cout << "Nom: " << name << " Puissance: " << power << " Prix: " << basePrice;

	switch(engine)
	{
		case Petrol: cout << "Essence";break;
		case Diesel: cout << "Diesel";break;
		case Electric: cout << "Electrique";break;
		case Hybrid: cout << "Hybride";break;
	}
	cout << endl;
}