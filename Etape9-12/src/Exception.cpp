#include "Exception.h"

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