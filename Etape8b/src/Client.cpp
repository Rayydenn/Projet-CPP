#include "Client.h"



/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									CONSTRUCTEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

Client::Client():Actor()
{
	Gsm = "";
}

Client::Client(string nom, string prenom, int id, string tel):Actor(id,nom,prenom)
{
	Gsm = tel;
}

Client::Client(const Client& source):Actor(source)
{
	Gsm = source.Gsm;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									SETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

void Client::setGsm(string tel)
{
	Gsm = tel;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									GETTERS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

string Client::getGsm() const
{
	return Gsm;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									TUPLE/TOSTRING									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////

string Client::toString() const {
    return lastName + " " + firstName + " " + Gsm;
}

string Client::tuple() const {
    return std::to_string(this->Id) + ";" + lastName + ";" + firstName + ";" + Gsm;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*									OPERATEURS									*/
/////////////////////////////////////////////////////////////////////////////////////////////////////



ostream& operator<<(ostream& os, const Client& c)
{
	// '\n' est meilleur que endl

    os << "<Client>" << '\n';

    os << "<lastName>" << '\n';
    os << c.getLastName() << '\n';
    os << "</lastName>" << '\n';

    os << "<firstName>" << '\n';
    os << c.getFirstName() << '\n';
    os << "</firstName>" << '\n';

    os << "<id>" << '\n';
    os << c.getId() << '\n';
    os << "</id>" << '\n';

    os << "<gsm>" << '\n';
    os << c.getGsm() << '\n';
    os << "</gsm>" << '\n';

    os << "</Client>" << '\n';

    return os;
}

istream& operator>>(istream& is, Client& c)
{
    string line;

    // Aller à <Client>
    while (getline(is, line)) {
        if (line == "<Client>") break;
    }

    // <lastName>
    getline(is, line);  // <lastName>
    getline(is, line);
    c.setLastName(line);
    getline(is, line);  // </lastName>

    // <firstName>
    getline(is, line);  // <firstName>
    getline(is, line);
    c.setFirstName(line);
    getline(is, line);  // </firstName>

    // <id>
    getline(is, line);  // <id>
    getline(is, line);
    c.setId(stoi(line));
    getline(is, line);  // </id>

    // <gsm>
    getline(is, line);  // <gsm>
    getline(is, line);
    c.setGsm(line);
    getline(is, line);  // </gsm>

    getline(is, line);  // </Client>

    return is;
}

bool Client::operator<(const Client& c) const
{
    return this->getLastName() < c.getLastName();
}