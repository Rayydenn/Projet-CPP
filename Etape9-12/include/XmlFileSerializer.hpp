#pragma once
#include <fstream>
#include <iostream>
#include "XmlFileSerializerException.h"
#include <string>

using namespace std;

// template!!!
template <typename T>
class XmlFileSerializer
{
public:
    static const char READ;
    static const char WRITE;

private:
    fstream file;
    char mode;
    string fileName;
    string collectionName;


public:
    XmlFileSerializer(const XmlFileSerializer& fs) = delete;
    XmlFileSerializer() = delete;
    XmlFileSerializer(const string& fN, const char m);
    XmlFileSerializer(const string&, const char, const string&);
    ~XmlFileSerializer();

    void setFileName(const string);
    void setCollectionName(const string);
    void setMode(const char);

    string getFilename() const;
    string getCollectionName() const;
    bool isReadable() const;
    bool isWritable() const;

    void write(const T&);
    T read();

};

#include "../src/XmlFileSerializer.ipp"