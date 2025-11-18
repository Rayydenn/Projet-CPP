#include "Option.h"
#include <limits>
#include "OptionException.h"

using namespace carconfig;

////////////////////////////////////////////////////////////////////////////////////////////////
/*										CONSTRUCTEURS										  */
////////////////////////////////////////////////////////////////////////////////////////////////

Option::Option()
{
	setCode("0000");
	setLabel("Inconnu");
	setPrice(0.0f);
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
	if (c.length() != 4)
		throw OptionException("Le Code doit être composé de 4 caractères!");
	Code = c;
}

void Option::setLabel(const string l)
{
	if (l.empty())
		throw OptionException("Label vide");
	Label = l;
}

void Option::setPrice(const float p)
{
	if (p < 0)
		throw OptionException("Prix doit etre positif!");
	Prix = p;
}

////////////////////////////////////////////////////////////////////////////////////////////////
/*										OPERATEURS											  */
////////////////////////////////////////////////////////////////////////////////////////////////


namespace carconfig
{
	istream& operator>>(istream& is, Option& opt)
	{
		string code, label;
		float prix;

		cout << "Entrez le code (4 chars): " << endl;
		is >> code;
		if (code.length() != 4)
			throw OptionException("Code doit être composé de 4 caractères!");

		is.ignore();

		cout << "Entrez le nom de l'option: " << endl;
		getline(is, label);
		if (label.empty())
			throw OptionException("Le label ne doit pas être vide!");
		cout << "Entrez le prix: " << endl;
		is >> prix;
		if (prix < 0)
			throw OptionException("Le prix doit être positif!");

		is.ignore();

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
	if ((Prix - 50) < 0)
		throw OptionException("Prix ne peut pas être négatif après ristourne !");
	Prix -= 50;
	return *this;
}

Option Option::operator--(int)
{
	Option temp = *this;
	if ((Prix - 50) < 50)
		throw OptionException("Prix ne peut pas être négatif après ristourne !"); 
	Prix -= 50;
	return temp;
}


void Option::display() const
{
	cout << "Code: " << Code << endl << "Nom: " << Label << endl << "Prix: " << Prix << endl;
}