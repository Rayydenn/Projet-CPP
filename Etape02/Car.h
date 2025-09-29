#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Model.h"

class Car
{
private:
	char *name;
	Model model;

public:
	// Test 1 & 2
	Car();
	// Test 3
	Car(const char* nom, Model modele);
	Car(Car &source);
	~Car();
	
	void setName(const char*);
	void setModel(Model m);

	char* getName();
	Model getModel();

	void display();
};

#endif