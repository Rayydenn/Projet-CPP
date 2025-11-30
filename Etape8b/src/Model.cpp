#include "Model.h"
#include <cstring>
#include <iomanip>
using namespace std;


// Constructeurs
Model::Model()
{
	name = new char[20];
	setName(name);
	setPower(0);
	setEngine(Engine::Petrol);
	setBasePrice(0.0);
}

Model::Model(const char* n, const int p, const Engine e, const float prix)
{
	name = new char[20];
	setName(n);
	setPower(p);
	setEngine(e);
	setBasePrice(prix);
}
Model::Model(const Model &source)
{
	name = new char[20];
	setName(source.getName());
	setPower(source.getPower());
	setEngine(source.getEngine());
	setBasePrice(source.getBasePrice());
}

Model::~Model()
{
	delete[] name;
}

// SETTERS / GETTERS

void Model::setName(const char* n) 
{
	if (name != nullptr)
		delete[] name;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Model::setPower(int p)
{
	power = p;
}

void Model::setBasePrice(float prix)
{
	basePrice = prix;
}

void Model::setEngine(Engine e)
{
	engine = e;
}

void Model::setEngine(int val)
{
	switch(val)
	{
		case 0:
			engine = Petrol;
			break;
		case 1:
			engine = Diesel;
			break;
		case 2:
			engine = Electric;
			break;
		case 3:
			engine = Hybrid;
			break;
		default:
			engine = Petrol;
	}
}

char* Model::getName() const
{
	return name ? name : nullptr;
}

int Model::getPower() const
{
	return power;
}

float Model::getBasePrice() const
{
	return basePrice;
}

Engine Model::getEngine() const
{
	return engine;
}



istream& operator>>(istream& is, Model& m)
{
	string line;
	
	getline(is, line); // <Model>
    
    // Nom
    getline(is, line); // <Nom>
    getline(is, line); // nom
    m.setName(line.c_str());
    getline(is, line); // </Nom>

    // Power
    getline(is, line); // <Power>
    getline(is, line); // ligne = "68"
    m.setPower(stoi(line));
    getline(is, line); // </Power>

    // Price
    getline(is, line); // <Price>
    getline(is, line); // ligne = "12500"
    m.setBasePrice(stof(line));
    getline(is, line); // </Price>

    // Engine
    getline(is, line); // <Engine>
    getline(is, line); // ligne = "0"
    m.setEngine(stoi(line));
    getline(is, line); // </Engine>

    getline(is, line); // </Model>

	return is;
}

ostream& operator<<(ostream& os, const Model& m)
{
	os << "<Model>" << endl;
	os << "<Nom>" << endl;
	os << m.getName() << endl;
	os << "</Nom>" << endl;
	os << "<Power>" << endl;
    os << m.getPower() << endl;
    os << "</Power>" << endl;
    os << "<Price>" << endl;
    os << m.getBasePrice() << endl;
    os << "</Price>" << endl;
    os << "<Engine>" << endl;
    os << m.engine << endl;	
    os << "</Engine>" << endl;
    os << "</Model>" << endl;

	return os;
}


Model Model::operator+() const
{
	Model temp(*this);
	return temp;
}


// DISPLAY

void Model::display() const
{
	cout << "Nom : " << name << " Puissance : " << power << " Moteur : ";

	switch(engine)
	{
		case Petrol: cout << "Essence"; break;
		case Diesel: cout << "Diesel"; break;
		case Electric: cout << "Electrique"; break;
		case Hybrid: cout << "Hybride"; break;
	}

	cout << " Prix de Base : " << basePrice << " €" << endl;
}

string Model::toString() const {
    return string(name) + ", " +
           std::to_string(power) + ", " +
           std::to_string(engine) + ", " +
           std::to_string(basePrice) + "€";
}