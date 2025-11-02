#include "Employee.h"
#include "PasswordException.h"

using namespace carconfig;

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CONSTRUCTEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

const string Employee::SELLER = "Vendeur";
const string Employee::ADMINISTRATIVE = "Administratif";

Employee::Employee():Actor()
{
	Role = "";
	Login = "";
	Password = nullptr;
}

Employee::Employee(string nom, string prenom, int id, string login, string role):Actor(id, nom, prenom)
{
	Password = nullptr;
	setLogin(login);
	setRole(role);
}

Employee::Employee(Employee& source):Actor(source)
{
	setLogin(source.Login);
	setRole(source.Role);

	if (source.Password)
	{
		setPassword(*source.Password);
	}
	else
	{
		Password = nullptr;
	}
}

Employee::~Employee()
{
	delete Password;
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
		throw PasswordException("Attention! Sans mot de passe vous risquez de tout perdre !");

	if (pw.find(' ') != string::npos)
   		throw PasswordException("Le Mot de passe ne doit pas contenir d'espace !");

	if (pw.length() > 64)
		throw PasswordException("Le Mot de passe doit être de maximum 64 caractères (et de minimum 8 caractères) !");

   	if (pw.length() < 8)
   		throw PasswordException("Le Mot de passe doit être composé d'au moins 8 caractères (et de maximum 64 caractères) !");

   	delete Password;
   	Password = new string(pw);
}

void Employee::setRole(const string role)
{
	Role = role;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									GETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

string Employee::getPassword() const
{
	if (Password == nullptr)
		throw PasswordException("");
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
    std::string prefix = (Role == SELLER) ? "V" : "A";
    return "[" + prefix + std::to_string(Id) + "] " + lastName + " " + firstName;
}


string Employee::tuple() const {
    return std::to_string(Id) + ";" + lastName + ";" + firstName + ";" + Role;
}

void Employee::resetPassword() {
    delete Password;
    Password = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									OPERATEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

namespace carconfig
{
	Employee& Employee::operator=(const Employee& source)
	{
	    if (this == &source) return *this; // auto-affectation

	    setFirstName(source.firstName);
	    setLastName(source.lastName);
	    setId(source.Id);
	    setLogin(source.Login);
	    setRole(source.Role);

	    delete Password;
	    if (source.Password)
	        setPassword(*source.Password);
	    else
	        Password = nullptr;

	    return *this;
	}

	ostream& operator<<(ostream& os, const Employee& emp)
	{
		os << emp.toString();

		return os;
	}
}
