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


namespace carconfig
{
	istream& operator>>(istream& is, Option& opt)
	{
		string code, label;
		float prix;

		cout << "Entrez le code (4 chars): " << endl;
		is >> code;
		while (code.size() != 4)
		{
			cout << "4 caractères svp!" << endl;
			is >> code;
		}

		is.ignore();

		cout << "Entrez le nom de l'option: " << endl;
		getline(is, label);
		cout << "Entrez le prix: " << endl;
		is >> prix;

		opt.setCode(code);
		opt.setLabel(label);
		opt.setPrice(prix);

		return is;
	}

	ostream& operator<<(ostream& os, const Option& opt)
	{
		os << "Code: " << opt.getCode() << endl
		   << "Nom: " << opt.getLabel() << endl
		   << "Prix: " << opt.getPrice() << endl;
		return os;
	}
}

Option& Option::operator--()
{
	Prix -= 50;
	return *this;
}

Option Option::operator--(int)
{
	Option temp = *this;
	Prix -= 50;
	return temp;
}


void Option::display() const
{
	cout << "Code: " << Code << endl << "Nom: " << Label << endl << "Prix: " << Prix << endl;
}