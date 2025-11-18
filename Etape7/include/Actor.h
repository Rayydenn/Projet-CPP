#pragma once
#include <iostream>
#include "Person.h"
#include <tuple>
#include <string>

using namespace std;

namespace carconfig
{
	class Actor : public Person
	{
	protected:
		int Id;

	public:
		Actor();
		Actor(int, string, string);
		virtual ~Actor();

		void setId(int id);
		int getId() const;

		virtual string toString() const = 0;
	    virtual string tuple() const = 0;

	    friend ostream& operator<<(ostream& os, const Actor& a);
	    friend istream& operator>>(istream& is, Actor& a);
	};
}