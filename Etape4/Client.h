#pragma once
#include <iostream>
#include "Actor.h"
#include <tuple>
#include <string>

using namespace std;

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
	void setGsm(string tel);

	string getLastName() const;
	string getFirstName() const;
	string getGsm() const;

	string tuple() const;
	string toString() const;

	friend ostream& operator<<(ostream& os, const Client c);

	void display();
};