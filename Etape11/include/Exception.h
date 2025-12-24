#pragma once
#include <string>
#include <iostream>

using namespace std;


class Exception
{
protected:
	string msg;
public:
	Exception();
	Exception(const string& m);
	
	void setmsg(const string& m);
	string getmsg() const;
};
