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
	// Test 2 / 3
	//Model(const char*, int, Engine, float);
	// Test 4
	//Model(const char*, int, Engine, float);
	//Model(Model&);
	// Test 5
	//Model();
	// Test 6
	Model(const char*, int, Engine, float);
	Model(Model&);
	~Model();


	void display();
	void setName(const char*);
	void setPower(int);
	void setEngine(Engine);
	void setBasePrice(float);

    char* getName();
    int getPower();
    float getBasePrice();
    Engine getEngine();


};