#include "PasswordException.h"

using namespace carconfig;

PasswordException::PasswordException():Exception()
{

}

PasswordException::PasswordException(string m, int c):Exception(m)
{
	ErrorType(c);
}

void PasswordException::ErrorType(int c)
{
	if (c == 1)
		cerr << endl << "INVALID_LENGTH " << endl;
	else if (c == 2)
		cerr << endl << "ALPHA_MISSING " << endl;
	else if (c == 3)
		cerr << endl << "DIGIT_MISSING " << endl;
	else if (c == 4)
		cerr << endl << "NO_PASSWORD " << endl;
}
