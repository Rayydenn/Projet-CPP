#include "Actor.h"

Actor::Actor()
{
	Id = -1;
	lastName = "";
	firstName = "";
}

Actor::Actor(int id, string nom, string prenom)
{
	Id = id;
	lastName = nom;
	firstName = prenom;
}
