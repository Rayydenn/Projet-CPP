#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <cstring>
#include "Option.h"
#include "Model.h"
#include <cstring>

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
		~Car();

		void display() const;
		void addOption(const Option& option);
		void setName(const string n);
		void setModel(const Model& m);
		void removeOption(const string);
		Model getModel() const;
		string getName() const;
		float getPrice() const;

		Car& operator=(const Car& other);          
        Car operator+(const Option& opt) const;
        Car operator-(const Option& opt) const;
        Car operator-(const string code) const;
        bool operator>(const Car& other) const;
        bool operator<(const Car& other) const;
        bool operator==(const Car& other) const;
        Option* operator[](int index) const;

        friend ostream& operator<<(ostream& os, const Car& other);

	};
	Car operator+(const Option& opt, const Car& c);
}



#endif
