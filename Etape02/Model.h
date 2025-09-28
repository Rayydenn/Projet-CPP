#include <iostream>

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
}