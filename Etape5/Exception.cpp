#include "Exception.h"

using namespace carconfig;

Exception::Exception()
{
	msg = "Error: ";
}

Exception::Exception(string m)
{
	setmsg(m);
}

void Exception::setmsg(string m)
{
	msg = m;
}

string Exception::getmsg() const
{
	return msg;
}