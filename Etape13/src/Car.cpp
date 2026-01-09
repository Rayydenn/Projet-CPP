#include "Car.h"
#include "OptionException.h"
#include "XmlFileSerializer.hpp"
#include "XmlFileSerializerException.h"

////////////////////////////////////////////////////////////////////////////////////////////////
/*										CONSTRUCTEURS										  */
////////////////////////////////////////////////////////////////////////////////////////////////


Car::Car()
{
	Name = "";
	for (int i = 0; i < 5; i++)
        option[i] = nullptr;
}

Car::Car(const string n, const Model m)
{
	Name = n;
	setModel(m);
	for (int i = 0; i < 5; i++)
		option[i] = nullptr; 
}

Car::Car(const Car& source)
{
	Name = source.Name;
	setModel(source.model);
	for (int i = 0; i < 5; i++)
    {
        if (source.option[i] != nullptr)
            option[i] = new Option(*source.option[i]);
        else
            option[i] = nullptr;
    }
}

Car::~Car()
{
	for (int i = 0; i < 5; ++i)
    {
        delete option[i];
        option[i] = nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										OPTION												  */
////////////////////////////////////////////////////////////////////////////////////////////////


void Car::addOption(const Option& opt)
{
	for (int i = 0; i < 5;i++)
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
	throw OptionException("Code non trouvé");
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										SETTERS/GETTERS										  */
////////////////////////////////////////////////////////////////////////////////////////////////


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

	string image = m.getImage();

	if (!image.empty())
	{
		model.setImage(m.getImage());
	}	

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
	for (int i = 0; i < 5;i++)
	{
		if (option[i] != nullptr)
		{
			total += option[i]->getPrice();
		}
	}

	total += model.getBasePrice();
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

		for (int i = 0; i < 5;i++)
		{
			delete option[i];
			option[i] = nullptr;
		}

		for (int i = 0; i < 5;i++)
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



Car operator+(const Option& opt, const Car& c)
{
	Car temp(c);
	temp.addOption(opt);
	return temp;
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

ostream& operator<<(ostream& os, const Car& other)
{
	os << "<Car>" << endl;
	os << "<Nom>" << endl;
	os << other.Name << endl;
	os << "</Nom>" << endl;
	os << other.model;
	os << "<Options>" << endl;
	for (int i = 0;i<5;i++)
	{
		if (other.option[i] != nullptr)
			os << *(other.option[i]);
	}
	os << "</Options>" << endl;
	os << "</Car>" << endl;
	return os;
}
istream& operator>>(istream& is, Car& other)
{
	string line;
	getline(is, line);
	getline(is, line);
	getline(is, line);
	other.setName(line);
	getline(is, line);
	is >> other.model;
	getline(is, line);
	int i = 0;
	while (i < 5)
	{
		streampos pos = is.tellg();
		getline(is, line);
		if (line == "</Options>")
			break;

		is.seekg(pos);

		if (other.option[i] != nullptr)
        	delete other.option[i];

		other.option[i] = new Option;
		is >> *other.option[i];

		i++;
	}
	getline(is, line);
	return is;
}



Option* Car::operator[](int index) const
{
    if (index < 0 || index >= 5)
        return nullptr;
    return option[index];
}


void Car::display() const
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

///////////////////////////////////////////////////////////////////////////
// 								SAVE et LOAD							 //
///////////////////////////////////////////////////////////////////////////

void Car::save()
{
	fstream fd;
	string fn = Name + ".xml";
	fd.open(fn, ios::out);
	if (!fd.is_open())
	{
		cout << "Fichier introuvable";
		return;
	}
	fd << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	fd << *this;
	fd.close();
}

void Car::load(string projectName)
{
	fstream fd;
	string fn = projectName + ".xml";
	fd.open(fn, ios::in);
	if(!fd.is_open())
	{
		cout << "Fichier introuvable";
		return;
	}
	cout << "Ouverture reussi" << endl;
	string line;
	getline(fd, line);
	fd >> *this;
	fd.close();

}