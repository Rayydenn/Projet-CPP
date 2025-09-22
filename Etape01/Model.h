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

	Model& Model::model1(const char*, int, Engine, float);
	Model& Model::model2(Model);
public:
	Model(const char* name, int power, Engine engine, float basePrice);
	~Model();

	void display();
	void setName(const char*);
	void setPower(int);
	void setEngine(Engine);
	void setBasePrice(float);

    const char* getName();
    int getPower();
    float getBasePrice();
    Engine getEngine();


};