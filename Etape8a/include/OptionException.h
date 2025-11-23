#pragma once
#include <string>
#include <iostream>
#include "Exception.h"

using namespace std;

namespace carconfig
{
	class OptionException: public Exception
	{
	public:
		OptionException();
		OptionException(const string&);
	};	
}
