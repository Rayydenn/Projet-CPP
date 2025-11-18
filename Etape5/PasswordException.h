#pragma once
#include <string>
#include <iostream>
#include "Exception.h"

using namespace std;

namespace carconfig
{
	class PasswordException: public Exception
	{
	private:
		int code;
	public:
		PasswordException();
		PasswordException(string, int);

		void ErrorType(int);
	};	
}
