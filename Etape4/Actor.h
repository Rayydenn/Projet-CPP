#pragma once
#include <iostream>
#include "Person.h"
#include <tuple>
#include <string>

using namespace std;

class Actor : public Person
{
protected:
	int Id;

public:
	Actor();
	Actor(int, string, string);
};
