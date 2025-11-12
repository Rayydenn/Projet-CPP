#include "Person.h"

using namespace carconfig;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CONSTRUCTEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									SETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

void Person::setLastName(string lN) 
{
	lastName = lN;
}

void Person::setFirstName(string fN) 
{
	firstName = fN;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									GETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

string Person::getLastName() const
{
	return lastName;
}

string Person::getFirstName() const
{
	return firstName;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									OPERATEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

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

namespace carconfig
{
	ostream& operator<<(ostream& os, const Person& p)
	{
		os << "<Person>" << endl;
		os << "<Nom>" << endl;
		os << p.getLastName() << endl;
		os << "</Nom>" << endl;
		os << "<Prenom>" << endl;
		os << p.getFirstName() << endl;
		os << "</Prenom>" << endl;
		os << "</Person>" << endl;

		return os;
	}

	istream& operator>>(istream& is, Person& p)
	{
		string line;
		getline(is, line);
		getline(is, line);
		getline(is, line);
		p.setLastName(line);
		getline(is, line);
		getline(is, line);
		getline(is, line);
		p.setFirstName(line);
		getline(is, line);
		getline(is, line);

		return is;
	}
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