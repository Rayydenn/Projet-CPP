#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <cstring>
#include "Model.h"

using namespace std;

namespace carconfig
{
	class Car
	{
	private:
		string Name;
		Model model;


	public:
		Car();
		Car(const string name, const Model& m);
		Car(const Car &source);
		~Car();

		void display() const;
		void setName(const string n);
		void setModel(const Model&);
		Model getModel() const;
		string getName() const;


	};
}
#endif