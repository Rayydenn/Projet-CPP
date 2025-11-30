#pragma once
#include <iostream>
#include "Actor.h"
#include <tuple>
#include <string>
#include "Person.h"

using namespace std;

class Employee: public Actor
{
private:
	string Role;
	string Login;
	string *Password;

public:
	Employee();
	Employee(string, string, int, string, string);
	Employee(const Employee& source);
	virtual ~Employee();


	static const string SELLER;
    static const string ADMINISTRATIVE;

    void setLogin(const string login);
    void setPassword(const string &pw);
    void setRole(const string role);

    string getLogin() const;
    string getPassword() const;
    string getRole() const;

    string toString() const;
    string tuple() const;

    Employee& operator=(const Employee& source);

    friend ostream& operator<<(ostream& os, const Employee& emp);
    bool operator<(const Employee& other) const;

    void resetPassword();
};
