#include "Application.h"

Application::Application() {
	cmd = -1;
	iter = UserList.begin();
}

void Application::Run() {
	int n;

	while (true) {
		n = getCommand();
		switch (n) {
		case 0:
			return;
			break;
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Update();
			break;
		case 4:
			Search();
			break;
		case 5:
			Print();
			break;
		default:
			cout << "Wrong Input!" << '\n';
			break;
		}
	}
}

int Application::getCommand() {
	int n;
	cout << "====================" << '\n';
	cout << "1. Insert User" << '\n';
	cout << "2. Delete User" << '\n';
	cout << "3. Update User" << '\n';
	cout << "4. Search User" << '\n';
	cout << "5. Print All User" << '\n';
	cout << "0. Exit" << '\n';
	cout << "====================" << '\n';
	cout << "Enter a command number: ";
	cin >> n;
	system("cls");
	return n;
}

void Application::Insert() {
	string name;
	int age;
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the age: ";
	cin >> age;

	User temp(name, age);

	if(UserList.empty())
		UserList.push_back(temp);
	else {
		bool check = true;
		ResetIterator();
		while (iter != UserList.end()) {
			if ((*iter).CompareUser(temp) == EQUAL) {
				check = false;
				break;
			}
			else
				++iter;
		}
		if (check) {
			UserList.push_back(temp);
			cout << "Insert Complete!" << '\n';
		}
		else
			cout << "Data Duplication!" << '\n';
		
	}

	UserList.sort(); // iter를 통해 순서에 맞게 삽입하는 과정을 거치면 속도가 빨라질 것.
}

void Application::Delete() {
	if (UserList.empty())
		cout << "No data!" << '\n';
	else {
		string name;
		int age;
		bool check = false;

		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the age: ";
		cin >> age;
		User temp(name, age);

		ResetIterator();
		while (iter != UserList.end()) {
			if ((*iter).CompareUser(temp) == EQUAL) {
				iter = UserList.erase(iter);
				check = true;
				cout << "Delete Complete!" << '\n';
				break;
			}
			else
				++iter;
		}
		if (!check)
			cout << "Delete Incomplete!" << '\n';
	}
}

void Application::Update() {
	if (UserList.empty())
		cout << "No data!" << '\n';
	else {
		string name;
		int age;
		bool check = false;
		bool fnd = false;

		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the age: ";
		cin >> age;
		User temp(name, age);

		ResetIterator();
		while (iter != UserList.end()) {
			if ((*iter).CompareUser(temp) == EQUAL) {
				cout << "Enter the name: ";
				cin >> name;
				cout << "Enter the age: ";
				cin >> age;

				// 중복 데이터 찾기
				User t(name, age);
				list<User>::iterator it;
				it = UserList.begin();
				while (it != UserList.end()) {
					if ((*it).CompareUser(t) == EQUAL) {
						// 중복 데이터일 경우에만 출력
						cout << "Data Duplication!" << '\n';
						fnd = true;
						break;
					}
					else
						++it;
				}

				// 중복 데이터가 아니면 Update
				if (!fnd) {
					(*iter).setName(name);
					(*iter).setAge(age);
					check = true;
					cout << "Update Complete!" << '\n';
					break;
				}
				else
					break;
			}
			else
				++iter;
		}

		// 없는 데이터 입력시에만 출력
		if (!check && !fnd)
			cout << "Update Incomplete!" << '\n';
		else
			UserList.sort();
	}
}

void Application::Search() {
	if (UserList.empty())
		cout << "No data!" << '\n';
	else {
		string name;
		bool check = false;

		cout << "Enter the name: ";
		cin >> name;

		ResetIterator();
		while (iter != UserList.end()) {
			if ((*iter).getName() == name) {
				cout << "Age: " << (*iter).getAge() << '\n';
				check = true;
			}
			++iter;
		}
		if (!check)
			cout << "Search Incomplete!" << '\n';
	}
}

void Application::Print() {
	if (UserList.empty())
		cout << "No data!" << '\n';
	else {
		int i = 1;
		ResetIterator();
		while (iter != UserList.end()) {
			cout << "No." << i++ << '\n';
			cout << " - Name: " << (*iter).getName() << '\n';
			cout << " - Age: " << (*iter).getAge() << '\n';
			++iter;
		}
	}
}

void Application::ResetIterator() {
	iter = UserList.begin();
}