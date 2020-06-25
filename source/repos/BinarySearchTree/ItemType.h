#include <iostream>
using namespace std;

class ItemType
{
private:
	string name;
	int age;
public:
	ItemType()
	{
		name = "";
		age = 0;
	}
	~ItemType() {}
	string GetName()
	{
		return name;
	}
	int GetAge()
	{
		return age;
	}
	void SetName(string name_)
	{
		name = name_;
	}
	void SetAge(int age_)
	{
		age = age_;
	}
	void SetAll(string name_, int age_)
	{
		SetName(name_);
		SetAge(age_);
	}
	void SetNameByKB()
	{
		cout << "Name : ";
		cin >> name;
	}
	void SetAgeByKB()
	{
		cout << "Age : ";
		cin >> age;
	}
	void SetAllByKB()
	{
		SetNameByKB();
		SetAgeByKB();
	}
	void ShowName()
	{
		cout << "Name : " << name << endl;
	}
	void ShowAge()
	{
		cout << "Age : " << age << endl;
	}
	void ShowAll()
	{
		ShowName();
		ShowAge();
	}
	bool operator >(ItemType& item)
	{
		if (this->GetName() > item.GetName())
			return true;
		else if (this->GetName() == item.GetName())
			if (this->GetAge() > item.GetAge())
				return true;
		return false;
	}
	bool operator <(ItemType& item)
	{
		if (this->GetName() < item.GetName())
			return true;
		else if (this->GetName() == item.GetName())
			if (this->GetAge() < item.GetAge())
				return true;
		return false;
	}
	bool operator ==(ItemType& item)
	{
		if (this->GetName() == item.GetName() && this->GetAge() == item.GetAge())
			return true;
		else
			return false;
	}

	friend ostream& operator <<(ostream& out, ItemType& item)
	{
		out << "Name : " << item.GetName() << endl;
		out << "Age : " << item.GetAge() << endl;

		return out;
	}
};