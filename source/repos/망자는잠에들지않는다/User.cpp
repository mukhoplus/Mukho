#include "User.h"

User::User() {
	name = "";
	age = -1;
}

User::User(string name, int age) {
	this->name = name;
	this->age = age;
}

string User::getName() {
	return name;
}

int User::getAge() {
	return age;
}

void User::setName(string name) {
	this->name = name;
}

void User::setAge(int age) {
	this->age = age;
}

bool User::operator >(User& u) {
	return ( (this->name > u.name) || (this->name == u.name && this->age > u.age));
}

bool User::operator ==(User& u) {
	return (this->name == u.name && this->age == u.age);
}

bool User::operator <(User& u) {
	return ((this->name < u.name) || (this->name == u.name && this->age < u.age));
}