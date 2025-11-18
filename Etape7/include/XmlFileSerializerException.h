#pragma once
#include "Exception.h"
#include <iostream>

class XmlFileSerializeException:Exception()
{
private:
	int code;
	string msg;
public:
	XmlFileSerializeException();
	XmlFileSerializeException(string m);

	int getCode();
}