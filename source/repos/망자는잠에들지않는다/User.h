#include <iostream>
#include <string>
#include <list>
using namespace std;
enum RelationType { GREATER, EQUAL, LESS };

class User {
private:
	string name;
	int age;
public:
	User();
	User(string name, int age);
	~User() {};

	string getName();
	int getAge();
	void setName(string name);
	void setAge(int age);

	bool operator >(User& u);
	bool operator ==(User& u);
	bool operator <(User& u);

	RelationType CompareUser(const User& u) {
		if (this->name > u.name)
			return GREATER;
		else if (this->name == u.name) {
			if (this->age > u.age)
				return GREATER;
			else if (this->age == u.age)
				return EQUAL;
			else
				return LESS;
		}
		else
			return LESS;
	}
};