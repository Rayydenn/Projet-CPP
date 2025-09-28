#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstring>

enum Engine {Petrol, Diesel, Electric, Hybrid};

class Model
{
private:
	char *name;
	int power;
	float basePrice;
	Engine engine;

public:
	Model(const char*, int, Engine, float);
	~Model();

	void display();
};

#endif