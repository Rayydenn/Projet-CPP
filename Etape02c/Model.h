#pragma once
#include <iostream>
using namespace std;

enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model
{
private:
	char* name;
	int power;
	float basePrice;
	Engine engine;

public:
	Model();
	Model(const char*,const int,const Engine,const float);
	Model(const Model&);
	~Model();


	void display() const;
	void setName(const char*);
	void setPower(int);
	void setEngine(Engine);
	void setBasePrice(float);

    char* getName() const;
    int getPower() const;
    float getBasePrice() const;
    Engine getEngine() const;


};