#pragma once
#include <string>
using namespace std;

class Contract
{
private:
    int    id;
    int    idSeller;
    int    idClient;
    string projectName;


public:
    static int contractId;
    Contract();
    Contract(int id, int idSeller, int idClient, const string &projectName);

    int    getId()        const;
    int    getIdSeller()  const;
    int    getIdClient()  const;
    string getProjectName() const;

    void setId(int v);
    void setIdSeller(int v);
    void setIdClient(int v);
    void setProjectName(const string &n);

    string tuple(const string &sellerName, const string &clientName) const;

    bool operator<(const Contract &contr) const;
};

ostream &operator<<(ostream &os, const Contract &c);
istream &operator>>(istream &is, Contract &c);