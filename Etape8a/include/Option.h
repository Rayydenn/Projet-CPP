#ifndef OPTION_H
#define OPTION_H
#include <cstring>
#include <iostream>

using namespace std;



class Option
{
	private:
		string Code;
		string Label;
		float Prix;

	public:
		Option();
		Option(const string&, const string&, const float);
		Option(const Option &source);

		void setCode(const string c);
		void setPrice(const float p);
		void setLabel(const string l);


		string getCode() const;
		float getPrice() const;
		string getLabel() const;

		friend istream& operator>>(istream& is, Option& opt);
    	friend ostream& operator<<(ostream& os, const Option& opt);
    	Option& operator--();  // Prefixe (--op)
    	Option operator--(int);  // Postfixe (op--)

		void display() const; // Je laisse pour simplifier l'operateur >> de Car.cpp

};

#endif