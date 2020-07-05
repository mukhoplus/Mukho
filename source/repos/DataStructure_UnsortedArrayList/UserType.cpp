#include "UserType.h"

UserType::UserType()
{
	id = "";
	name = "";
}
UserType::~UserType()
{}

string UserType::GetId()
{
	return id;
}
string UserType::GetName()
{
	return name;
}

void UserType::SetId(string id_)
{
	id = id_;
}
void UserType::SetName(string name_)
{
	name = name_;
}
void UserType::SetAll(string id_, string name_)
{
	SetId(id_);
	SetName(name_);
}
void UserType::SetIdFromKB()
{
	cout << "ID : ";
	cin >> id;
}
void UserType::SetNameFromKB()
{
	cout << "Name : ";
	cin >> name;
}
void UserType::SetAllFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

void UserType::PrintId()
{
	cout << "ID : " << id << endl;
}
void UserType::PrintName()
{
	cout << "Name : " << name << endl;
}
void UserType::PrintAll()
{
	PrintId();
	PrintName();
}

int UserType::ReadDataFromFile(ifstream& fin)
{
	fin >> id;
	fin >> name;

	return 1;
}
int UserType::WriteDataFromFile(ofstream& fout)
{
	fout << endl;
	fout << id << " ";
	fout << name;

	return 1;
}

RelationType UserType::ConpareById(const UserType& data)
{
	if (this->id > data.id)
		return GREATER;
	else if (this->id < data.id)
		return LESS;
	else
		return EQUAL;
}
RelationType UserType::ConpareByName(const UserType& data)
{
	if (this->name > data.name)
		return GREATER;
	else if (this->name < data.name)
		return LESS;
	else
		return EQUAL;
}