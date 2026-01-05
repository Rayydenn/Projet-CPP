#include "Contract.h"
#include <sstream>
#include <ostream>
#include <istream>

using namespace std;

int Contract::contractId = 0;

Contract::Contract() : id(0), idSeller(0), idClient(0), projectName("")
{
}

Contract::Contract(int i, int s, int c, const string &p)
    : id(i), idSeller(s), idClient(c), projectName(p)
{
}

int Contract::getId() const
{
    return id;
}

int Contract::getIdSeller() const
{
    return idSeller;
}

int Contract::getIdClient() const
{
    return idClient;
}

string Contract::getProjectName() const
{
    return projectName;
}

void Contract::setId(int v)
{
    id = v;
}

void Contract::setIdSeller(int v)
{
    idSeller = v;
}

void Contract::setIdClient(int v)
{
    idClient = v;
}

void Contract::setProjectName(const string &n)
{
    projectName = n;
}

string Contract::tuple(const string &sellerName, const string &clientName) const
{
    return to_string(id) + ";" + sellerName + ";" + clientName + ";" + projectName;
}

bool Contract::operator<(const Contract &contr) const
{
    return id < contr.id;
}

ostream &operator<<(std::ostream &os, const Contract &c)
{
    os << "<Contract>" << endl;
    os << "<id>" << endl;
    os << c.getId() << endl;
    os << "</id>" << endl;
    os << "<seller>" << endl;
    os << c.getIdSeller() << endl;
    os << "</seller>" << endl;
    os << "<client>" << endl;
    os << c.getIdClient() << endl;
    os << "</client>" << endl;
    os << "<projectName>" << endl;
    os << c.getProjectName() << endl;
    os << "</projectName>" << endl;
    os << "</Contract>";
    return os;
}


istream &operator>>(istream &is, Contract &c)
{
    string line;
    
    getline(is, line);

    getline(is, line);
    getline(is, line);
    c.setId(stoi(line));
    getline(is, line);

    getline(is, line);
    getline(is, line);
    c.setIdSeller(stoi(line));
    getline(is, line);

    getline(is, line);
    getline(is, line);
    c.setIdClient(stoi(line));
    getline(is, line);

    getline(is, line);
    getline(is, line);
    c.setProjectName(line);
    getline(is, line);

    getline(is, line);

    return is;
}
