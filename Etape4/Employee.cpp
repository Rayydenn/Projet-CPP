#include "Employee.h"


const string SELLER = "Vendeur";
const string ADMINISTRATIVE = "Administratif";

Employee::Employee()
{
	Role = "";
	Login = "";
	Password = nullptr;
}

Employee::Employee(string nom, string prenom, int id, string login, string role)
{
	firstName = nom;
	lastName = prenom;
	Id = id;
	Password = nullptr;
	Login = login;
	Role = role;
}

Employee::Employee(Employee& source)
{
	firstName = source.firstName;
	lastName = source.lastName;
	Id = source.Id;
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

void Employee::setLastName(const string nom)
{
	lastName = nom;
}

void Employee::setFirstName(const string prenom)
{
	firstName = prenom;
}

void Employee::setId(const int id)
{
	Id = id;
}

void Employee::setLogin(const string login)
{
	Login = login;
}

void Employee::setPassword(const string &pw)
{
	if (!Password)
        Password = new string(pw);
}

void Employee::setRole(const string role)
{
	Role = role;
}

int Employee::getId() const
{
	return Id;
}

string Employee::getLastName() const
{
	return lastName;
}

string Employee::getFirstName() const
{
	return firstName;
}

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

string Employee::toString() const
{
	return "Id: " + to_string(Id)
		 + ", Nom: " + lastName
		 + ", Prenom: " + firstName
		 + ", Login: " + Login
		 + ", Password: " + (Password ? *Password : "")
		 + ", Role: " + Role;
}

string Employee::tuple() const
{
	return to_string(Id) + ", " + lastName + ", " + firstName + ", " + Login + ", " + (Password ? *Password : "") + ", " + Role;
}

void Employee::resetPassword() {
    delete Password;
    Password = nullptr;
}


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

void Employee::display()
{
	cout << endl
		 << "Id: " << Id << endl
		 << "Nom: " << lastName << endl
		 << "Prenom: " << firstName << endl
		 << "Login: " << Login << endl
		 << "Password: " << (Password ? *Password : "") << endl
		 << "Role: " << Role << endl;
}