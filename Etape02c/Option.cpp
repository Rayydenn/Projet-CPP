#include "Option.h"

using namespace carconfig;

Option::Option()
{
	setCode("FFFF");
	setLabel("Default");
	setPrice(0.0);
}

Option::Option(const string c, const string l, const float p)
{
	setCode(c);
	setLabel(l);
	setPrice(p);
}

Option::Option(const Option& source)
{
	setCode(source.getCode());
	setLabel(source.getLabel());
	setPrice(source.getPrice());
}

void Option::setCode(const string n)
{
	Code = n;
}

void Option::setLabel(const string l)
{
	Label = l;
}

void Option::setPrice(const float p)
{
	Prix = p;
}

string Option::getCode() const
{
	return Code;
}

string Option::getLabel() const
{
	return Label;
}

float Option::getPrice() const
{
	return Prix;
}

void Option::display() const
{
	cout << "Code: " << Code << endl << "Nom: " << Label << endl << "Prix: " << Prix << endl;
}