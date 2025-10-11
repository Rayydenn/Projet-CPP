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
		Car(const string name, const Model m);
		Car(const Car &source);

		void display();
		void addOption(const Option& option);
		void setName(const string n);
		void setModel(const Model m);
		void removeOption(const string);
		Model getModel();
		string getName();
		float getPrice();


	};
}
#endif