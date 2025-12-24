#include "Garage.h"
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
    auto it = employees.cbegin();
	while (it != employees.cend() && it->getId() != id)
	{
		it++;
	}
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