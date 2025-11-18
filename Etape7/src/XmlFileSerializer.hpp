#pragma once
#include "XmlFileSerializer.h"

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fN, Mode m, const string& cN)
{
	setFileName(fN);
	setCollectionName(cN);
	setMode(m);

	if (mode == WRITE)
	{
		ofstream ofs(fileName);
		if (!ofs)
			throw XmlFileSerializerException("Erreur d'ouverture du fichier en écriture");
		ofs << "<" << collectionName << ">" << endl;
	} else
	{
		ifstream ifs(fileName);
		if (!ifs)
			throw XmlFileSerializerException("Erreur d'ouverture du fichier en lecture");
	}
}

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
	ofstream ofs(fileName);
	if (ofs)
		ofs << "</" << collectionName << ">" << endl;
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
void XmlFileSerializer<T>::setMode(const Mode m)
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
	return mode;
}

template <typename T>
bool XmlFileSerializer<T>::isWritable() const
{
	return mode;
}

template <typename T>
void XmlFileSerializer<T>::write(const T& val)
{
	if (mode != WRITE)
		throw XmlFileSerializerException("Fichier non ouvert en écriture");

	ofstream ofs(fileName);
	if (!ofs)
		throw XmlFileSerializerException("Erreur d'ouverture en écriture");

	ofs << "<value>" << endl
		<< val  << endl
		<< "</value>" << endl;
}


template <typename T>
T XmlFileSerializer<T>::read()
{
	if (mode != READ)
		throw XmlFileSerializerException("Fichier non ouvert en lecture");

	ifstream ifs(fileName);
	if (!ifs)
		throw XmlFileSerializerException("Erreur d'ouverture en lecture");

	T val{};
	if (!(ifs >> val))
		throw XmlFileSerializerException("Erreur de lecture du fichier");

	return val;
}