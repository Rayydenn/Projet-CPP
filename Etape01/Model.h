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