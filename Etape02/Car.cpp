#include "Car.h"

using namespace std;


Car::Car()
{
	name = new char[50];
	model = Model();
}

Car::~Car()
{
	if (name!=nullptr)
	{
		delete[] name;
	}
}

void Car::setName(const char* nom)
{
	if (name!=nullptr)
		delete[] name;
	name = new char[strlen(nom) + 1];
	strcpy(name, nom);
}

void Car::setModel(Model modele)
{
	model = modele;
}

char* Car::getName()
{
	return name;
}

Model Car::getModel()
{
	return model;
}


void Car::display()
{
	cout << "Nom: " << name << endl;
	model.display();
}