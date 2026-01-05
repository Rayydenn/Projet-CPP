#include "Garage.h"
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <Contract.h>

Garage Garage::instance;
Car Garage::currentProject;
int Garage::idLoggedEmployee = -1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////      CONSTRUCTEUR      ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Garage::Garage()
{
    // employé admin par défaut : administratif (role 0)
    addEmployee("Admin", "Admin", "admin", 0);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////       MODEL       ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void   Garage::addModel(const Model & m)
{
	models.push_back(m);
}

void   Garage::displayAllModels() const
{
	int index = 0;
	for (list<Model>::const_iterator it = models.cbegin(); it != models.cend(); it++)
	{
		cout << "[M " << index << "]" << it->toString() << endl;
		index++;
	}

}

Model  Garage::getModel(int index) const
{
	if (index < 0 || index >= models.size())
		return Model();
	auto it = models.cbegin();
	advance(it, index);
	if (it == models.cend())
		return Model();
	return *it;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////       OPTION       /////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void Garage::addOption(const Option& o)
{
	options.push_back(o);
}

void Garage::displayAllOptions() const
{
	int index = 0;
	for (list<Option>::const_iterator it = options.cbegin(); it != options.cend(); it++)
	{
		cout << "[O " << index << "]" << it->toString() << endl;
		index++;
	}
}

Option Garage::getOption(int index)
{
	if (index < 0 || index >= options.size())
		return Option();
	auto it = options.cbegin();
	advance(it, index);
	if (it == options.cend())
		return Option();
	return *it;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////       CLIENT       //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int    Garage::addClient(string lastName,string firstName,string gsm)
{
	clients.insert(Client(lastName, firstName, Actor::currentId ,gsm));
	cout << "Client Id: " << Actor::currentId << endl;
	Actor::currentId++;
	return 1;
}

void Garage::displayClients() const
{
	int index = 0;
	for (set<Client>::const_iterator it = clients.cbegin(); it != clients.cend(); it++)
	{
		cout << "[C " << index << "] " << it->toString() << " (ID: " << it->getId() << ")" << endl;
		index++;
	}
}

void   Garage::deleteClientByIndex(int index)
{
	auto it = clients.cbegin();
	advance(it, index);
	if (it != clients.cend())
	{
		cout << "Deleting [C " << index << "] " << it->toString() << " (ID: " << it->getId() << ")" << endl;
		clients.erase(it);
	}
	else
		cout << "index hors limite" << endl;
}

void   Garage::deleteClientById(int id)
{
	auto it = clients.cbegin();
	while (it != clients.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != clients.cend())
	{
		cout << "Deleting Client Id: " << id << " " << it->toString() << endl;
		clients.erase(it);
	}
	else
		cout << "id hors limite" << endl;

	if (hasContractsForClient(id))
	{
	    cout << "Impossible de supprimer ce client: contrats existants" << endl;
	    
	    return;
	}


}

Client Garage::findClientByIndex(int index) const
{
	if (index < 0 || index >= clients.size())
	{
	    cout << "Index hors limite" << endl;
	    return Client();
	}

	auto it = clients.cbegin();
	advance(it, index);
	if (it != clients.cend())
		return *it;
	else
		cout << "Index hors limite" << endl;

	return Client();
}

Client Garage::findClientById(int id) const
{
	if (id < 0)
	{
	    cout << "Index hors limite" << endl;
	    return Client();
	}

	auto it = clients.cbegin();
	while (it != clients.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != clients.cend())
		return *it;
	else
		cout << "Id hors limite" << endl;

	return Client();
}

int Garage::getNbClients()const
{
    return clients.size();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////       EMPLOYEE       ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int Garage::addEmployee(string lastName,string firstName,string login, string role, int id, string* Password)
{
	int finalId;
	if (id == 0)
		finalId = ++Actor::currentId;
	else
		finalId = id;

	Employee e(lastName, firstName, finalId, login, role);

	if (Password != nullptr)
		e.setPassword(*Password);

	employees.insert(e);
	cout << "Employee Id: " << Actor::currentId << endl;
	return 1;
}

int Garage::addEmployee(string lastName, string firstName, string login, int role)
{
	Employee e;

	e.setRole(role);
	string rolestr = e.getRole();
	return addEmployee(lastName, firstName, login, rolestr);
}

int Garage::updateEmployee(const Employee& e, int id)
{
    auto it = employees.begin();
	while (it != employees.end() && it->getId() != id)
	    ++it;

	if (it != employees.end())
	    employees.erase(it);

	employees.insert(e);
	cout << "Id Employee: " << id << endl;
	return 1;
}

void Garage::displayEmployees() const
{
	int index = 0;
	for (set<Employee>::const_iterator it = employees.cbegin(); it != employees.cend(); it++)
	{
		cout << "[E " << index << "] " << it->toString() << " (ID: " << it->getId() << ")" << endl;
		index++;
	}
}

void     Garage::deleteEmployeeByIndex(int index)
{
	auto it = employees.cbegin();
	advance(it, index);
	if (it != employees.cend())
	{
		cout << "Deleting [E " << index << "] " << it->toString() << " (ID: " << it->getId() << ")" << endl;
		employees.erase(it);
	}
	else
		cout << "index hors limite" << endl;
}

void     Garage::deleteEmployeeById(int id)
{
	auto it = employees.cbegin();
	while (it != employees.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != employees.cend())
	{
		cout << "Deleting Employee Id: " << id << " " << it->toString() << endl;
		employees.erase(it);
	}
	else
		cout << "id hors limite" << endl;

	if (hasContractsForSeller(id))
	{
	    cout << "Impossible de supprimer ce vendeur: contrats existants" << endl;
	    return;
	}

}

Employee Garage::findEmployeeByIndex(int index) const
{
	auto it = employees.cbegin();
	advance(it, index);
	if (it != employees.cend())
		return *it;
	else
		cout << "Index hors limite" << endl;
	
	return Employee();
}

Employee Garage::findEmployeeById(int id) const
{
	auto it = employees.cbegin();
	while (it != employees.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != employees.cend())
		return *it;
	else
		cout << "Id hors limite" << endl;

	return Employee();
}

int Garage::getNbEmployees() const
{
    return employees.size();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////       INSTANCE       ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


Garage& Garage::getInstance()
{
	return instance;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////       Current Project       ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

Car& Garage::getCurrentProject()
{
	return currentProject;
}

void Garage::resetCurrentProject()
{
	currentProject = Car();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////       Import Model/ Options       //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


void Garage::importModelsFromCsv(string filename)
{
	fstream fd;
	fd.open(filename, ios::in);
	if(!fd.is_open())
	{
		cout << "Fichier introuvable";
		return;
	}
	string line;
	getline(fd, line); // skip entete
	while (getline(fd, line))
	{
		string name, basePriceStr, powerStr, image, engineStr;
		istringstream iss(line);
		getline(iss, name, ';');
		getline(iss, powerStr, ';');
		getline(iss, engineStr, ';');
		getline(iss, image, ';');
		getline(iss, basePriceStr, ';');

		// creer un model pour la combobox
		Model m;

		m.setName(name.c_str());
		m.setBasePrice(stof(basePriceStr));
		m.setEngine(engineStr);
		m.setPower(stoi(powerStr));
		m.setImage(image);

		// créer une liste pour que quand on appelle cette fonction dans applicgarage on peut parcourir la liste
		addModel(m);

	}
}
void Garage::importOptionsFromCsv(string filename)
{
	fstream fd;
	fd.open(filename, ios::in);
	if(!fd.is_open())
	{
		cout << "Fichier introuvable";
		return;
	}
	string line;
	getline(fd, line); // skip entete
	while (getline(fd, line))
	{
		string code, label, priceStr;
		istringstream iss(line);
		getline(iss, code, ';');
		getline(iss, label, ';');
		getline(iss, priceStr, ';');

		// creer une option pour la combobox
		Option o;
		try
		{
			o.setCode(code);
			o.setLabel(label);
			o.setPrice(stof(priceStr));			
		}
		catch(OptionException& op)
		{
	        cout << op.getmsg();
		}

		// Liste pour l'appel dans ApplicGarage.cpp
		addOption(o);

	}
}

void Garage::setId(int i)
{
	Garage::idLoggedEmployee = i;
}

int Garage::getId() const
{
	return Garage::idLoggedEmployee;
}

///////////////////////////////////////////////////////////////////////////

int Garage::save()
{
	int i = 0, count = 0;
	string Nom;
	const char* NomFichier;
	Nom = "employees.xml";
	XmlFileSerializer<Employee> *fe = new XmlFileSerializer<Employee>(Nom, XmlFileSerializer<Employee>::WRITE, "Employees");
	auto it = employees.cbegin();
	while (it != employees.cend())
	{
		Employee e = findEmployeeByIndex(i);
		fe->write(e);
		i++;
		count++;
		it++;
	}

	delete fe;
	i = 0;
	Nom = "clients.xml";
	XmlFileSerializer<Client> *fc = new XmlFileSerializer<Client>(Nom, XmlFileSerializer<Client>::WRITE, "Clients");
	auto itc = clients.cbegin();
	while (itc != clients.cend())
	{
		Client c = findClientByIndex(i);
		fc->write(c);
		i++;
		itc++;
	}
	delete fc;

	Nom = "contracts.xml";
    XmlFileSerializer<Contract> *fct = new XmlFileSerializer<Contract>(Nom, XmlFileSerializer<Contract>::WRITE, "Contracts");

    auto its = contracts.cbegin();
    for(auto its = contracts.cbegin(); its != contracts.cend(); ++its)
	{
	    fct->write(*its);
	}
    delete fct;

	Nom = "config.dat";
	NomFichier = Nom.c_str();
	int fd = open(NomFichier, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		cerr << "Erreur d'ouverture du fichier" << endl;
		return -1;
	}
	write(fd, &Actor::currentId, sizeof(Actor::currentId));
	cout << "Id: " << Actor::currentId << endl;
	write(fd, &count, sizeof(int));
	cout << "Compteur Employee: " << count << endl;
	i = 0;

	while (i < count)
	{
		Credentials cred;
		Employee e = findEmployeeByIndex(i);
		strncpy(cred.login, e.getLogin().c_str(), sizeof(cred.login) - 1);
		cred.login[sizeof(cred.login)-1] = '\0';
		cout << "Login: " << cred.login << endl;

		try
		{
			strncpy(cred.password, e.getPassword().c_str(), sizeof(cred.password)-1);
			cred.password[sizeof(cred.password)-1] = '\0';
		}
		catch(PasswordException &p)
		{
			cred.password[0] = '\0';
		}

		cout << "Password: " << cred.password << endl;
		crypt(cred);
		cout << "Apres cryptage: " << endl;
		cout << endl << "Login: " << cred.login << endl << "Password: " << cred.password << endl;
		cout << endl << endl;
		write(fd, &cred, sizeof(Credentials));
		i++;
	}
	close(fd);

	return 1;
}

int Garage::load()
{
	string fn;

	fn = "employees.xml";
	XmlFileSerializer<Employee> *fe = nullptr;

	try
	{
		fe = new XmlFileSerializer<Employee>(fn, XmlFileSerializer<Employee>::READ);
	}
	catch (const XmlFileSerializerException& x)
	{
		cout << "Erreur: " << x.getmsg() << endl;
	}
	if (fe != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				Employee e = fe->read();
				if (e.getLogin() != "admin")
					addEmployee(e.getLastName(), e.getFirstName(), e.getLogin(), e.getRole());
			}
			catch (const XmlFileSerializerException& x)
			{
				if (x.getCode() == XmlFileSerializerException::END_OF_FILE)
				{
					end = true;
				}
				else
				{
					cout << x.getmsg() << endl;
					break;
				}
			}
		}
		delete fe;
	}

	fn = "clients.xml";
	XmlFileSerializer<Client> *fc = nullptr;

	try
	{
		fc = new XmlFileSerializer<Client>(fn, XmlFileSerializer<Client>::READ);
	}
	catch (const XmlFileSerializerException& x)
	{
		cout << "Erreur: " << x.getmsg() << endl;
	}

	if (fc != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				Client c = fc->read();
				addClient(c.getLastName(), c.getFirstName(), c.getGsm());
			}
			catch (const XmlFileSerializerException &x)
			{
				if (x.getCode() == XmlFileSerializerException::END_OF_FILE)
				{
					end = true;
				}
				else
				{
					cout << x.getmsg() << endl;
					break;
				}
			}
		}
		delete fc;
	}

    fn = "contracts.xml";
    XmlFileSerializer<Contract> *fct = nullptr;

    try
    {
        fct = new XmlFileSerializer<Contract>(fn, XmlFileSerializer<Contract>::READ);
    }
    catch (const XmlFileSerializerException &x)
    {
        cout << "Erreur: " << x.getmsg() << endl;
    }

    if (fct != nullptr)
    {
        bool end = false;
        while (!end)
        {
            try
            {
                Contract c = fct->read();
                
                addContract(c.getIdSeller(), c.getIdClient(), c.getProjectName());
            }
            catch (const XmlFileSerializerException &x)
            {
                if (x.getCode() == XmlFileSerializerException::END_OF_FILE)
                    end = true;
                else
                {
                    cout << x.getmsg() << endl;
                    break;
                }
            }
        }
        delete fct;
    }


	fn = "config.dat";
	const char *NomFichier = fn.c_str();
	int count;
	int fd = open(NomFichier, O_RDONLY, 0777);
	if (fd == -1)
	{
		cerr << "Erreur lors de l'ouverture du fichier" << endl;
		return -1;
	}
	if (read(fd, &Actor::currentId, sizeof(Actor::currentId)) < 1)
	{
		cerr << "Erreur: Données incorrectes" << endl;
		return -1;
	}
	if (read(fd, &count, sizeof(int)) < 1)
	{
		cerr << "Erreur: Données incorrectes" << endl;
		return -1;
	}

	int i = 0;
	while (i < count)
	{
		Credentials cred;
		Employee e = findEmployeeByIndex(i);
		if (read(fd, &cred, sizeof(cred)) < 1)
		{
			cerr << "Erreur: Données incorrectes" << endl;
			return -1;
		}

		decrypt(cred);
		e.setLogin(string(cred.login));
		if (cred.password[0] != '\0')
		{
			e.setPassword(cred.password);
		}
		updateEmployee(e, e.getId());
		i++;
	}
	close(fd);
	return 1;
}

void Garage::crypt(Credentials &c)
{
	for (int i = 0; i < strlen(c.login); i++)
	{
		int val = c.login[i] + 9;
		if (val > 255)
			val -= 255;
		c.login[i] = val;
	}

	for (int i = 0; i < strlen(c.password); i++)
	{
		int val = c.password[i] + 5;

		if (val > 255)
			val -= 255;

		c.password[i] = val;
	}
}

void Garage::decrypt(Credentials& c)
{
	for (int i = 0;i < strlen(c.login);i++)
	{
		int val = c.login[i] - 9;
		if (val < 0)
			val += 255;
		c.login[i] = val;
	}

	for (int i = 0; i < strlen(c.password); i++)
	{
		int val = c.password[i] - 5;
		if (val < 0)
			val += 255;
		c.password[i] = val;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////  Contrats       //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int Garage::addContract(int idSeller, int idClient, const string &projectName)
{
    int newId = ++Contract::contractId;

    Contract c(newId, idSeller, idClient, projectName);
    contracts.insert(c);
    cout << "Nb contrats = " << contracts.size() << endl;
    return newId;
}

Contract Garage::findContractByIndex(int index) const
{
    if (index < 0 || index >= contracts.size())
        return Contract();

    auto it = contracts.cbegin();
    advance(it, index);
    if (it != contracts.cend())
        return *it;
    return Contract();
}

void Garage::deleteContractByIndex(int index)
{
    auto it = contracts.cbegin();
    advance(it, index);
    if (it != contracts.cend())
        contracts.erase(it);
}

int Garage::getNbContracts() const
{
    return contracts.size();
}

bool Garage::hasContractsForSeller(int idSeller) const
{
    for (const auto &c : contracts)
        if (c.getIdSeller() == idSeller) return true;

    return false;
}

bool Garage::hasContractsForClient(int idClient) const
{
    for (const auto &c : contracts)
        if (c.getIdClient() == idClient) return true;

    return false;
}
