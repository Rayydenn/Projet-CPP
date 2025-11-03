#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <cstring>
#include "Option.h"
#include "Model.h"

using namespace std;

namespace carconfig
{
	class Car
	{
	private:
		string Name;
		Model model;
		Option* option[5];


	public:
		Car();
		Car(const string name, const Model& m);
		Car(const Car &source);

		void display() const;
		void addOption(const Option& option);
		void setName(const string n);
		void setModel(const Model&);
		void removeOption(const string);
		Model getModel() const;
		string getName() const;
		float getPrice() const;


	};
}
#endif