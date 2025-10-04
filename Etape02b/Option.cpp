#include "Option.h"
#include <cstring>

namespace carconfig
{
	Option::Option()
	{
		Code[0] = '\0';
		Label = nullptr;
		Price = 0.0f;
	}

	Option::Option(const char* c,const char* nom, float prix)
	{
		strncpy(Code, c, 4);
		Code[4] = '\0';
		Label = new char[strlen(nom) + 1];
		strcpy(Label, nom);
		Price = prix;
	}

	Option::Option(const Option &source)
	{
		strncpy(Code, source.Code, 4);
		Code[4] = '\0';
		Label = new char[strlen(source.Label) + 1];
		strcpy(Label, source.Label);
		Price = source.Price;
	}

	Option::~Option()
	{
		delete[] Label;
	}

	void Option::setCode(const char* c)
	{
		strcpy(Code, c);
		Code[4] = '\0';
	}

	void Option::setLabel(const char* nom)
	{
		Label = new char[strlen(nom) + 1];
		strcpy(Label, nom);
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


