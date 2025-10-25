#include "Client.h"

Client::Client()
{
	Gsm = "";
	Id = 0;
	firstName = "";
	lastName = "";
}

Client::Client(string nom, string prenom, int id, string tel)
{
	Id = id;
	firstName = prenom;
	lastName = nom;
	Gsm = tel;
}

Client::Client(const Client& source)
{
	Id = source.Id;
	firstName = source.firstName;
	lastName = source.lastName;
	Gsm = source.Gsm;
}

void Client::setLastName(string n)
{
	lastName = n;
}

void Client::setFirstName(string f)
{
	firstName = f;
}

void Client::setId(int id)
{
	Id = id;
}

void Client::setGsm(string tel)
{
	Gsm = tel;
}

string Client::getLastName() const
{
	return lastName;
}

string Client::getFirstName() const
{
	return firstName;
}

int Client::getId() const
{
	return Id;
}

string Client::getGsm() const
{
	return Gsm;
}

string Client::toString() const
{
	return "Id: " + to_string(Id) 
		  + ", Nom: " + lastName 
		  + ", Prenom: " + firstName 
		  + ", Gsm: " + Gsm;
}

string Client::tuple() const
{
	return to_string(Id) + ", " + lastName + ", " + firstName + ", " + Gsm;
}

ostream& operator<<(ostream& os, const Client c)
{
	os << c.toString();
	return os;
}

void Client::display()
{
	cout << "Id: " << Id << endl
		 << "Nom: " << lastName << endl
	     << "Prenom: " << firstName << endl
	     << "Gsm: " << Gsm << endl;
}