#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
protected:
	string lastName;
	string firstName;

public:
	Person();
	Person(string, string);
	~Person();

	void setLastName(string);
	void setFirstName(string);

	string getLastName() const;
	string getFirstName() const;

	Person& operator=(const Person& p);
	friend istream& operator>>(istream& is, Person& p);
	friend ostream& operator<<(ostream& os, const Person& p);
};