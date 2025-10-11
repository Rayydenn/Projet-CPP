#include "Car.h"
#include <cstring>

using namespace std;


Car::Car()
{
	name = "";
	model = Model();
}

Car::Car(const string &nom, Model modele)
{
	name = nom;
	model = modele;
}

Car::Car(Car &source)
{
	setName(source.getName());
	model = source.model;
}


void Car::setName(const string &nom)
{
	name = nom;
}

void Car::setModel(Model modele)
{
	model = modele;
}

string& Car::getName()
{
	return name;
}

Model Car::getModel()
{
	return model;
}


void Car::display()
{
	cout << "Nom du Projet: " << name << endl;
	model.display();
}