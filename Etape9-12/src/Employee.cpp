#include "Employee.h"
#include "PasswordException.h"
#include <cctype>


/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CONSTRUCTEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

const string Employee::SELLER = "Vendeur";
const string Employee::ADMINISTRATIVE = "Administratif";

Employee::Employee():Actor()
{
	setRole(Role);
	setLogin(Login);
	Password = nullptr;
}

Employee::Employee(string nom, string prenom, int id, string login, string role):Actor(id, nom, prenom)
{
	Password = nullptr;
	setLogin(login);
	setRole(role);
}

Employee::Employee(const Employee& source):Actor(source)
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

void Employee::resetPassword() {
    if (Password != nullptr)
	{
   		delete Password;
   		Password = nullptr;
	}
    Password = nullptr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									OPERATEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////


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
   		Password = nullptr;
	}

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

bool Employee::operator<(const Employee& e) const
{
	return this->getLastName() < e.getLastName();
}