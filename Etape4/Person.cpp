#include "Person.h"

Person::Person()
{
	lastName = "";
	firstName = "";
}

Person::Person(string lN, string fN)
{
	lastName = lN;
	firstName = fN;
}

void Person::setLastName(string lN) 
{
	lastName = lN;
}

void Person::setFirstName(string fN) 
{
	firstName = fN;
}

string Person::getLastName() const
{
	return lastName;
}

string Person::getFirstName() const
{
	return firstName;
}

istream& operator>>(istream& is, Person& p)
{
	string nom, prenom;

	cout << "Nom" << endl;
	getline(is, nom);

	cout << "Prenom" << endl;
	getline(is, prenom);

	p.setLastName(nom);
	p.setFirstName(prenom);

	return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << "Nom: " << p.getLastName() << endl
	   << "Prenom: " << p.getFirstName() << endl;

	return os;
}

Person& Person::operator=(const Person& p)
{
	if (this != &p)
	{
		lastName = p.lastName;
		firstName = p.firstName;
	}

	return *this;
}