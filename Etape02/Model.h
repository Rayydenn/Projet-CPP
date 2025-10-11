#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstring>
using namespace std;

enum Engine {Petrol, Diesel, Electric, Hybrid};

class Car;

class Model
{
	friend class Car;
private:
	string name;
	int power;
	float basePrice;
	Engine engine;

public:
	Model();
	Model(const string&, int, Engine, float);

	void display();
};

#endif