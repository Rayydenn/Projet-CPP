#include "Exception.h"

using namespace carconfig;

Exception::Exception()
{
	setmsg("Error404");
}

Exception::Exception(string m)
{
	setmsg(m);
}

void Exception::setmsg(string m)
{
	msg = m;
}

string Exception::getMessage() const
{
	return msg;
}