#pragma once
#include <iostream>
#include "Person.h"
#include <tuple>
#include <string>

using namespace std;

class Actor : public Person
{
protected:
	int Id;

public:
	Actor();
	Actor(int, string, string);

	void display();
};

class Client : public Actor
{
private:
	string Gsm;

public:
	Client();
	Client(string, string, int, string);
	Client(const Client& source);


	void setLastName(string n);
	void setFirstName(string f);
	void setId(int id);
	void setGsm(string tel);

	string getLastName() const;
	string getFirstName() const;
	int getId() const;
	string getGsm() const;

	string tuple() const;
	string toString() const;

	friend ostream& operator<<(ostream& os, const Client c);

	void display();
};