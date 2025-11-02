#pragma once
#include <string>
#include <iostream>
#include "Exception.h"

using namespace std;

namespace carconfig
{
	class PasswordException: public Exception
	{
	public:
		PasswordException();
		PasswordException(string);
	};	
}
