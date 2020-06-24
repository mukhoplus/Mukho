#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

class Application
{
private:
	int command;
	LinkedList<ItemType> List;
public:
	Application();
	~Application();

	void Run();
	int GetCommand(int number);

	void Insert();
	void Delete();
	void Update();
	void Show();
	void Search();
};

Application::Application()
{
	command = -1;
}
Application::~Application()
{
	List.MakeEmpty();
}

void Application::Run()
{
	while (1)
	{
		command = GetCommand(command);
		switch (command)
		{
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
			Show();
			break;
		case 5:
			Search();
			break;
		case 0:
			return;
			break;
		default:
			break;
		}
	}
}
int Application::GetCommand(int number)
{
	cout << "1. 추가" << endl;
	cout << "2. 삭제" << endl;
	cout << "3. 수정" << endl;
	cout << "4. 출력" << endl;
	cout << "5. 검색" << endl;
	cout << "0. 종료" << endl;
	cout << "입력 : ";
	cin >> number;

	return number;
}

void Application::Insert()
{
	ItemType item;
	item.SetAllByKB();
	List.Insert(item);
}
void Application::Delete()
{
	ItemType item;
	item.SetAllByKB();
	List.Delete(item);
}
void Application::Update()
{
	ItemType item;
	cout << "수정할 item을 입력하세요." << endl;
	item.SetAllByKB();
	if (List.Get(item))
	{
		cout << "단, 나이만 바꿀 수 있습니다." << endl;
		item.SetAgeByKB();
		List.Update(item);
	}
	else
		cout << "수정할 데이터를 찾을 수 없습니다." << endl;
}
void Application::Show()
{
	ItemType item;

	List.ResetPointer();
	for(int i=0;i<List.GetLength();i++)
	{
		List.GetNextItem(item);
		item.ShowAll();
	}
}
void Application::Search()
{
	ItemType item;

	cout << "검색할 item의 이름을 입력하세요." << endl;
	item.SetNameByKB();

	ItemType temp;
	List.ResetPointer();
	for (int i = 0; i < List.GetLength(); i++)
	{
		List.GetNextItem(temp);
		if (temp.GetName().find(item.GetName()) != -1)
			temp.ShowAll();
	}
}