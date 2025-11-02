#include "Car.h"
#include "OptionException.h"

using namespace carconfig;

////////////////////////////////////////////////////////////////////////////////////////////////
/*										CONSTRUCTEURS										  */
////////////////////////////////////////////////////////////////////////////////////////////////

Car::Car()
{
	Name = "";
	model = Model();
	for (int i = 0; i < 20; i++)
        option[i] = nullptr;
}

Car::Car(const string n, const Model m)
{
	Name = n;
	setModel(m);
	for (int i = 0; i < 20; i++)
		option[i] = nullptr; 
}

Car::Car(const Car& source)
{
	Name = source.Name;
	setModel(source.model);
	for (int i = 0; i < 20; i++)
    {
        if (source.option[i] != nullptr)
            option[i] = new Option(*source.option[i]);
        else
            option[i] = nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										OPTIONS												  */
////////////////////////////////////////////////////////////////////////////////////////////////

void Car::addOption(const Option& opt)
{
	for (int i = 0; i < 20;i++)
	{
		if (option[i] != nullptr)
		{
			if (option[i]->getCode() == opt.getCode())
				throw OptionException("L'option existe deja");
		}
		else
		{
			option[i] = new Option(opt);
			return;
		}
	}

	throw OptionException("La liste est pleine");
}

void Car::removeOption(const string c)
{
	for (int i = 0; i < 20; i++)
	{
		if (option[i] != nullptr && option[i]->getCode() == c)
		{
			delete option[i];
			option[i] = nullptr;
			cout << "Option " << c << " supprimée." << endl;
            return;
		}
	}
	throw OptionException("Code non trouvé");
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										GETTERS/SETTERS										  */
////////////////////////////////////////////////////////////////////////////////////////////////

void Car::setName(const string n)
{
	Name = n;
}

void Car::setModel(const Model& m)
{
	model.setName(m.getName());
	model.setPower(m.getPower());
	model.setbasePrice(m.getbasePrice());
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

float Car::getPrice() const
{
	float total = 0.0f;
	for (int i = 0; i < 20;i++)
	{
		if (option[i] != nullptr)
		{
			total += option[i]->getPrice();
		}
	}

	total += model.getbasePrice();
	return total;
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										OPERATEURS											  */
////////////////////////////////////////////////////////////////////////////////////////////////

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		Name = other.Name;
		setModel(other.model);

		for (int i = 0; i < 20;i++)
		{
			delete option[i];
			option[i] = nullptr;
		}

		for (int i = 0; i < 20;i++)
		{
			if (other.option[i] != nullptr)
			{
				option[i] = new Option(*other.option[i]);
			}
		}

	}

	return *this;
}

Car Car::operator+(const Option& opt) const
{
	Car temp(*this);
	temp.addOption(opt);
	return temp;
}

Car Car::operator-(const Option& opt) const
{
	Car temp(*this);
	temp.removeOption(opt.getCode());
	return temp;
}

Car Car::operator-(const string c) const
{
	Car temp(*this);
	temp.removeOption(c);
	return temp;
}

namespace carconfig {

	Car operator+(const Option& opt, const Car& c)
	{
		Car temp(c);
		temp.addOption(opt);
		return temp;
	}

}

bool Car::operator>(const Car& other) const
{
	return this->getPrice() > other.getPrice();
}

bool Car::operator<(const Car& other) const
{
	return this->getPrice() < other.getPrice();
}

bool Car::operator==(const Car& other) const
{
	return this->getPrice() == other.getPrice();
}

namespace carconfig
{
	ostream& operator<<(ostream& os, const Car& other)
	{
		other.display();

		return os;
	}
}


Option* Car::operator[](int index) const
{
    if (index < 0 || index >= 20)
        return nullptr;  // Sécurité pour éviter les débordements
    return option[index];
}


void Car::display() const
{
	cout << "Nom du Projet: " << Name << endl;
	model.display();
	for (int i = 0; i < 20;i++)
	{
		if(option[i] != nullptr)
		{
			option[i]->display();
		}
	}
}