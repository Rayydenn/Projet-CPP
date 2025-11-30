#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#include "XmlFileSerializerException.h"

template <typename T>
const char XmlFileSerializer<T>::READ = 'r';

template <typename T>
const char XmlFileSerializer<T>::WRITE = 'w';


template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fn, const char m, const string& cn)
{
	fileName = fn;
	mode = m;
	collectionName = cn;
	if (isWritable())
	{
		file.open(getFilename(), ios::out);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");
		}
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		file << "<" << getCollectionName() << ">" << endl;
	}
	if (isReadable())
	{
		file.open(getFilename(), ios::in);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");
		}
		string line;
		getline(file, line);
		getline(file, line); // On recupere le <collectionName> dans line
		line = line.substr(1, line.length() - 2); // on enleve les "< >"
		collectionName = line;
	}
}

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fN, char m)
{
    fileName = fN;
    mode = m;

    if (isWritable())
	{
		file.open(getFilename(), ios::out);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");
		}
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
		file << "<" << getCollectionName() << ">" << endl;
	}
	if (isReadable())
	{
		file.open(getFilename(), ios::in);
		if(!file.is_open())
		{
			throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");
		}
		string line;
		getline(file, line);
		getline(file, line); // On recupere le <collectionName> dans line
		line = line.substr(1, line.length() - 2); // on enleve les "< >"
		collectionName = line;
	}
}

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
    if (isWritable() && file.is_open())
    {
        file << "</" << collectionName << ">" << endl;
        file.close();
    }
    else if (file.is_open())
    {
        file.close();
    }
}


template <typename T>
void XmlFileSerializer<T>::setFileName(const string fN)
{
	fileName = fN;
}

template <typename T>
void XmlFileSerializer<T>::setCollectionName(const string cN)
{
	collectionName = cN;
}

template <typename T>
void XmlFileSerializer<T>::setMode(const char m)
{
	mode = m;
}

template <typename T>
string XmlFileSerializer<T>::getFilename() const
{
	return fileName;
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName() const
{
	return collectionName;
}

template <typename T>
bool XmlFileSerializer<T>::isReadable() const
{
	if (mode == READ)
		return true;
	return false;
}

template <typename T>
bool XmlFileSerializer<T>::isWritable() const
{
	if (mode == WRITE)
		return true;
	return false;
}

template <typename T>
void XmlFileSerializer<T>::write(const T& var)
{
	if (isReadable())
	{
		throw(XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Ecriture en mode lecture impossible!"));
	}

	file << var << endl;
}


template <typename T>
T XmlFileSerializer<T>::read()
{
	if (isWritable())
		throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Fichier non ouvert en lecture");

	string line;
	streampos pos = file.tellg();
	string end = "</" + getCollectionName() + ">";
	file >> line;

	if (line == end)
	{
		throw(XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "Lecture de la fin du fichier!"));
	}
	file.seekg(pos);
	T type;
	file >> type;
	return type;
}