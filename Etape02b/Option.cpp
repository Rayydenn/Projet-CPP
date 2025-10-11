#include "Option.h"
#include <cstring>

namespace carconfig
{
	Option::Option()
	{
		Code = "";
		Label = "";
		Price = 0.0f;
	}

	Option::Option(const string& c,const string& nom, float prix)
	{
		Code = c;
		Label = nom;
		Price = prix;
	}

	Option::Option(const Option &source)
	{
		Code = source.Code;
		Label = source.Label;
		Price = source.Price;
	}

	void Option::setCode(const string& c)
	{
		Code = c;
	}

	void Option::setLabel(const string& nom)
	{
		Label = nom;
	}

	void Option::setPrice(float prix)
	{
		Price = prix;
	}


	void Option::display()
	{
		cout << "Code: " << Code << endl << "Nom: " << Label << endl << "Prix: " << Price << endl;
	}
}


