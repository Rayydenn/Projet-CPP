#include "PasswordException.h"

using namespace carconfig;

PasswordException::PasswordException():Exception()
{

}

PasswordException::PasswordException(string m):Exception(m)
{

}