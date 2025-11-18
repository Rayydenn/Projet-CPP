#pragma once
#include <fstream>
#include <iostream>
#include "XmlFileSerializerException.h"
#include <stirng>

using namespace std;

// template!!!
template <typename T>
class XmfFileSerializer
{
public:
	enum Mode { READ, WRITE };

private:
	Mode mode;
	string fileName;
	string collectionName;


public:
	 XmlFileSerializer(const string&, Mode, const string&);
    ~XmlFileSerializer();

    void setFileName(const string);
    void setCollectionName(const string);
    void setMode(const Mode);

    string getFilename() const;
    string getCollectionName() const;
    bool isReadable() const;
    bool isWritable() const;

    void write(const T& val);
    T read();

}

#include "XmlFileSerializer.hpp"