#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace carconfig
{
	class Exception
	{
	protected:
		string msg;
	public:
		Exception();
		Exception(string m);
		
		void setmsg(string m);
		string getMessage() const;
	};
}