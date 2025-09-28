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
	Car();
	~Car();
	
	void setName(const char*);
	void setModel(Model m);

	char* getName();
	Model getModel();

	void display();
};

#endif