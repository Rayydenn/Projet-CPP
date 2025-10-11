#include "Car.h"

using namespace carconfig;

Car::Car()
{
	Name = "";
	model = Model();
	for (int i = 0; i < 5; i++)
        option[i] = nullptr;
}

Car::Car(const string n, const Model m)
{
	Name = n;
	model = m;
	for (int i = 0; i < 5; i++)
		option[i] = nullptr; 
}

Car::Car(const Car& source)
{
	Name = source.Name;
	model = source.model;
	for (int i = 0; i < 5; i++)
    {
        if (source.option[i] != nullptr)
            option[i] = new Option(*source.option[i]);
        else
            option[i] = nullptr;
    }
}

void Car::addOption(const Option& opt)
{
	for (int i = 0; i <5;i++)
	{
		if (option[i] == nullptr)
		{
			option[i] = new Option(opt);
			return;
		}
	}

	cout << "Erreur, la liste d'option est pleine" << endl;
}

void Car::setName(const string n)
{
	Name = n;
}

void Car::setModel(const Model m)
{
	model = m;
}

void Car::removeOption(const string c)
{
	for (int i = 0; i < 5; i++)
	{
		if (option[i] != nullptr && option[i]->getCode() == c)
		{
			delete option[i];
			option[i] = nullptr;
			cout << "Option " << c << " supprimée." << endl;
            return;
		}
	}
	cout << "Option " << c << " non trouvée." << endl;
}

Model Car::getModel()
{
	return model;
}

string Car::getName()
{
	return Name;
}

float Car::getPrice()
{
	float total = 0.0f;
	for (int i = 0; i < 5;i++)
	{
		if (option[i] != nullptr)
		{
			total += option[i]->getPrice();
		}
	}

	total += model.getbasePrice();
	return total;
}

void Car::display()
{
	cout << "Nom du Projet: " << Name << endl;
	model.display();
	for (int i = 0; i < 5;i++)
	{
		if(option[i] != nullptr)
		{
			option[i]->display();
		}
	}
}