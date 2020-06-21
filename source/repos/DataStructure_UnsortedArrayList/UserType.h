#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };

class UserType
{
protected:
	string id;
	string name;
public:
	UserType();
	~UserType();

	string GetId();
	string GetName();

	void SetId(int id_);
	void SetName(string name_);
	void SetAll(int id_, string name_);
	void SetIdFromKB();
	void SetNameFromKB();
	void SetAllFromKB();

	void PrintId();
	void PrintName();
	void PrintAll();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataFromFile(ofstream& fout);

	RelationType ConpareById(const UserType& data);
	RelationType ConpareByName(const UserType& data);
};