#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Model.h"
#include <cstring>

using namespace std;

class Car
{
private:
	string name;
	Model model;

public:
	// Test 1 & 2
	Car();
	// Test 3
	Car(const string& nom, Model modele);
	Car(Car &source);
	
	void setName(const string&);
	void setModel(Model m);

	string &getName();
	Model getModel();

	void display();
};

#endif