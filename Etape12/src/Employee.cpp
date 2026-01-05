#include "Employee.h"
#include "PasswordException.h"
#include <cctype>


/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CONSTRUCTEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

const string Employee::SELLER = "Vendeur";
const string Employee::ADMINISTRATIVE = "Administratif";

Employee::Employee() : Actor(), Role(""), Login(""), Password(nullptr)
{
}


Employee::Employee(string nom, string prenom, int id, string login, string role):Actor(id, nom, prenom)
{
	Password = nullptr;
	setLogin(login);
	setRole(role);
}

Employee::Employee(string nom, string prenom, int id, string login, string role, string& pwd):Actor(id, nom, prenom)
{
	setPassword(pwd);
	setLogin(login);
	setRole(role);
}

Employee::Employee(const Employee& source) : Actor(source)
{
    Login = source.Login;
    Role  = source.Role;

    if (source.Password != nullptr)
        Password = new string(*source.Password);
    else
        Password = nullptr;
}

Employee::~Employee()
{
	if (Password != nullptr)
	{
   		delete Password;
   		Password = nullptr;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									SETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////


void Employee::setLogin(const string login)
{
	Login = login;
}

void Employee::setPassword(const string &pw)
{
	if (pw.empty())
		throw PasswordException("Pas de mot de passe", 4);

   	if (pw.length() < 6)
   		throw PasswordException("Le Mot de passe doit être composé d'au moins 6 caractères", 1);

   	bool alpha = false;
   	bool digit = false;

   	for (char c : pw)
   	{
   		if (isalpha(static_cast<unsigned char>(c)))
   			alpha = true;
   		else if (isdigit(static_cast<unsigned char>(c)))
   			digit = true;
   	}

   	if (!alpha)
   		throw PasswordException("Le Mot de passe doit contenir au moins 1 lettre !", 2);

   	if (!digit)
   		throw PasswordException("Le Mot de passe doit contenir au moins 1 chiffre !", 3);

   	if (Password != nullptr)
	{
   		delete Password;
   		Password = nullptr;
	}
   	Password = new string(pw);
}

void Employee::setRole(const string role)
{
	Role = role;
}

void Employee::setRole(const int role)
{
	switch(role)
	{
		case 0:
			Role = Employee::ADMINISTRATIVE;
			break;
		case 1:
			Role = Employee::SELLER;
			break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									GETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

string Employee::getPassword() const
{
	if (Password == nullptr)
		throw PasswordException("Pas de mot de passe", 4);
	return Password ? *Password : "";
}

string Employee::getLogin() const
{
	return Login;
}

string Employee::getRole() const
{
	return Role;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									TUPLE/STRING (PASSWORD RESET)									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

string Employee::toString() const {
    return lastName + " " + firstName;
}


string Employee::tuple() const {
    return std::to_string(Id) + ";" + lastName + ";" + firstName + ";" + Role;
}

void Employee::resetPassword()
{
    if (Password != nullptr)
    {
        delete Password;
        Password = nullptr;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									OPERATEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& s, const Employee& e)
{
	s << "<Employee>" << endl;

	s << "<lastName>" << endl;
	s << e.lastName << endl;
	s << "</lastName>" << endl;

	s << "<firstName>" << endl;
	s << e.firstName << endl;
	s << "</firstName>" << endl;

	s << "<id>" << endl;
	s << e.Id << endl;
	s << "</id>" << endl;

	s << "<login>" << endl;
	s << e.Login << endl;
	s << "</login>" << endl;

	s << "<role>" << endl;
	s << e.Role << endl;
	s << "</role>" << endl;

	s << "</Employee>";


	return s;
}

istream& operator>>(istream& s, Employee& e)
{
	string line;
	getline(s, line);

	getline(s, line);
	getline(s, line);
	e.setLastName(line);
	getline(s, line);

	getline(s, line);
	getline(s, line);
	e.setFirstName(line);
	getline(s, line);

	getline(s, line);
	getline(s, line);
	e.setId(stoi(line));
	getline(s, line);

	getline(s, line);
	getline(s, line);
	e.setLogin(line);
	getline(s, line);

	getline(s, line);
	getline(s, line);
	e.setRole(line);
	getline(s, line);

	getline(s, line);
	return s;
}


Employee& Employee::operator=(const Employee& source)
{
    if (this == &source) return *this; // auto-affectation

    setFirstName(source.firstName);
    setLastName(source.lastName);
    setId(source.Id);
    setLogin(source.Login);
    setRole(source.Role);

    if (Password != nullptr)
	{
   		delete Password;
	}

    if (source.Password)
        Password = new string(*source.Password);
    else
        Password = nullptr;

    return *this;
}

bool Employee::operator<(const Employee& e) const
{
	return this->getLastName() < e.getLastName();
}