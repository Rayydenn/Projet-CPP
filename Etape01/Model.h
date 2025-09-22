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
	Model(const char* name, int power, Engine engine, float basePrice);
	~Model();

	void display();
	void setName(const char* name);
	void setPower(int power);
	void setEngine(Engine engine);
	void setBasePrice(float basePrice);

    const char* getName();
    int getPower();
    float getBasePrice();
    Engine getEngine();


};