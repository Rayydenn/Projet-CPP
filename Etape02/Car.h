#include <iostream>
#include "Model.h"

enum Engine {Petrol, Diesel, Electric, Hybrid};

class Car
{
private:
	char *name;

public:
	Model model;
	Car();
	~Car();
	
	void setName(const char*);
	void setModel(Model);

	char* getName();
	Model getModel();


};