#include "Employee.h"

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
	Login = login;
	Role = role;
}

Employee::Employee(Employee& source):Actor(source)
{
	Login = source.Login;
	Role = source.Role;

	if (source.Password)
	{
		Password = new string(*source.Password);
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

Employee& Employee::operator=(const Employee& source)
{
    if (this == &source) return *this; // auto-affectation

    firstName = source.firstName;
    lastName = source.lastName;
    Id = source.Id;
    Login = source.Login;
    Role = source.Role;

    delete Password;
    if (source.Password)
        Password = new string(*source.Password);
    else
        Password = nullptr;

    return *this;
}

ostream& operator<<(ostream& os, const Employee& emp)
{
	os << emp.toString();

	return os;
}