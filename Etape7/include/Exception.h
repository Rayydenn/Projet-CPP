#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Exception
{
protected:
	string message;

public:
	Exception();
	Exception(string);
	void setMsg(string);
	string getMessage() const;
};