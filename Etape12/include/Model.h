#pragma once
#include <iostream>
#include <string>
using namespace std;


enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model
{
private:
	char* name;
	int power;
	float basePrice;
	Engine engine;
	string image;

public:
	Model();
	Model(const char*,const int,const Engine,const float);
	Model(const char*, const int, const Engine, const float, const string);
	Model(const char* n, const int p, const int e, const float prix, const string image);
	Model(const Model&);
	~Model();


	void display() const;
	void setName(const char*);
	void setPower(int);
	void setEngine(Engine);
	void setEngine(int);
	void setEngine(string);
	void setBasePrice(float);
	void setImage(string i);

    char* getName() const;
    int getPower() const;
    float getBasePrice() const;
    Engine getEngine() const;
    string toString() const;
    string getImage() const;



    friend istream& operator>>(istream& is, Model& m);
    friend ostream& operator<<(ostream& os, const Model& m);
    Model operator+() const;
    Model& operator=(const Model&);

};
