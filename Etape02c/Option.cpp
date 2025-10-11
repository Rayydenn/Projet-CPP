#include "Option.h"

using namespace carconfig;

Option::Option()
{
	Code = "";
	Label = "";
	Prix = 0.0f;
}

Option::Option(const string& c, const string& l, const float p)
{
	Code = c;
	Label = l;
	Prix = p;
}

Option::Option(const Option& source)
{
	Code = source.Code;
	Label = source.Label;
	Prix = source.Prix;
}

string Option::getCode()
{
	return Code;
}


float Option::getPrice()
{
	return Prix;
}

void Option::display()
{
	cout << "Code: " << Code << endl << "Nom: " << Label << endl << "Prix: " << Prix << endl;
}