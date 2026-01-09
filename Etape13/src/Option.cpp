#include "Option.h"
#include <limits>
#include "OptionException.h"


////////////////////////////////////////////////////////////////////////////////////////////////
/*										CONSTRUCTEURS										  */
////////////////////////////////////////////////////////////////////////////////////////////////

Option::Option()
{
	Code = "";
	Label = "Pas de nom";
	Prix = 0.0f;
}

Option::Option(const string& c, const string& l, const float p)
{
	setCode(c);
	setLabel(l);
	setPrice(p);
}

Option::Option(const Option& source)
{
	setCode(source.Code);
	setLabel(source.Label);
	setPrice(source.Prix);
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										GETTERS/SETTERS										  */
////////////////////////////////////////////////////////////////////////////////////////////////

string Option::getCode() const
{
	return Code;
}

float Option::getPrice() const
{
	return Prix;
}

string Option::getLabel() const
{
	return Label;
}

void Option::setCode(const string c)
{
	Code = c;
}

void Option::setLabel(const string l)
{
	Label = l;
}

void Option::setPrice(const float p)
{
	Prix = p;
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										OPERATEURS											  */
////////////////////////////////////////////////////////////////////////////////////////////////



istream& operator>>(istream& is, Option& opt)
{
	string line;

	getline(is, line);	// Option
	getline(is, line);	// Code
	getline(is, line);
	opt.setCode(line);
	getline(is, line);	// /Code

	getline(is, line);	// Label
	getline(is, line);
	opt.setLabel(line);
	getline(is, line);	// /Label

	getline(is, line);	// price
	getline(is, line);
	opt.setPrice(stof(line));
	getline(is, line);	// /price

	getline(is, line);	// /option

	return is;
}

ostream& operator<<(ostream& os, const Option& opt)
{
	os << "<Option>" << endl;
	os << "<code>" << endl;
	os << opt.Code << endl;
	os << "</code>" << endl;
	os << "<Label>" << endl;
	os << opt.Label << endl;
	os << "</Label>" << endl;
	os << "<Price>" << endl;
	os << opt.getPrice() << endl;
	os << "</Price>" << endl;
	os << "</Option>" << endl;
	return os;
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
	if (Prix < 0)
		throw OptionException("Il n'est pas possible de mettre une réduction de 50e sur ce produit");
	return temp;
}

Option& Option::operator=(const Option& o)
{
	if (this != &o)
	{
		Code = o.Code;
		Label = o.Label;
		Prix = o.Prix;
	}

	return *this;
}


void Option::display() const
{
	cout << "Code: " << Code << endl << "Nom: " << Label << endl << "Prix: " << Prix << endl;
}


string Option::toString() const {
    return Code + ", " +
           Label + ", " +
           std::to_string(Prix);
}