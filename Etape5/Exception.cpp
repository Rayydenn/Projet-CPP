#include "Exception.h"

using namespace carconfig;

Exception::Exception()
{
	setmsg("Error404");
}

Exception::Exception(const string& m)
{
	setmsg(m);
}

void Exception::setmsg(const string& m)
{
	msg = m;
}

string Exception::getmsg() const
{
	return msg;
}