#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstring>

enum Engine {Petrol, Diesel, Electric, Hybrid};

class Car;

class Model
{
	friend class Car;
private:
	char *name;
	int power;
	float basePrice;
	Engine engine;

public:
	Model();
	Model(const char*, int, Engine, float);
	//~Model();

	void display();
};

#endif