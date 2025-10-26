#include "Client.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CONSTRUCTEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

Client::Client()
{
	Gsm = "";
	Id = 0;
	firstName = "";
	lastName = "";
}

Client::Client(string nom, string prenom, int id, string tel):Actor(id,nom,prenom)
{
	Gsm = tel;
}

Client::Client(const Client& source):Actor(source)
{
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

string Client::getGsm() const
{
	return Gsm;
}

string Client::toString() const {
    return "[C" + std::to_string(Id) + "] " + lastName + " " + firstName;
}

string Client::tuple() const {
    return std::to_string(Id) + ";" + lastName + ";" + firstName + ";" + Gsm;
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