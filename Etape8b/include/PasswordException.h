#pragma once
#include <string>
#include <iostream>
#include "Exception.h"

using namespace std;


class PasswordException: public Exception
{
private:
	int code;
public:
	PasswordException();
	PasswordException(const string&, int);

	void ErrorType(int);
};	
