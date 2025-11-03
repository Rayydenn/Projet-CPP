#include "Car.h"

using namespace carconfig;

Car::Car()
{
	Name = "";
	setModel(model);
}

Car::Car(const string n, const Model& m)
{
	Name = n;
	setModel(m);
}

Car::Car(const Car& source)
{
	setName(source.getName());
	setModel(source.getModel());
}

Car::~Car()
{
}

void Car::setName(const string n)
{
	Name = n;
}

void Car::setModel(const Model& m)
{
	model.setName(m.getName());
	model.setPower(m.getPower());
	model.setBasePrice(m.getBasePrice());
	model.setEngine(m.getEngine());
}

Model Car::getModel() const
{
	return model;
}

string Car::getName() const
{
	return Name;
}

void Car::display() const
{
	cout << "Nom du Projet: " << Name << endl;
	model.display();
}