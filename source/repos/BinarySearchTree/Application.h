#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

class Application
{
private:
	int command;
	BinarySearchTree<ItemType> Tree;
public:
	Application();
	~Application();

	void Run();
	int GetCommand(int number);

	void Insert();
	void Delete();
	void Update();
	void ShowPre();
	void ShowIn();
	void ShowPost();
	void Search();
};

Application::Application()
{
	command = -1;
}
Application::~Application()
{
	Tree.MakeEmpty();
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
			ShowPre();
			break;
		case 4:
			ShowIn();
			break;
		case 5:
			ShowPost();
			break;
		case 6:
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
	cout << "3. Preorder 출력" << endl;
	cout << "4. Inorder 출력" << endl;
	cout << "5. Postorder 출력" << endl;
	cout << "6. 검색" << endl;
	cout << "0. 종료" << endl;
	cout << "입력 : ";
	cin >> number;

	return number;
}

void Application::Insert()
{
	ItemType item;
	item.SetAllByKB();
	Tree.InsertItem(item);
}
void Application::Delete()
{
	ItemType item;
	item.SetAllByKB();
	Tree.DeleteItem(item);
}
void Application::Update()
{
	ItemType item;
	cout << "수정할 item을 입력하세요." << endl;
	item.SetAllByKB();
	
	bool found;
	Tree.SearchItem(item, found);
	if (found == true)
		item.ShowAll();
	else
		cout << "찾을 수 없습니다." << endl;
}
void Application::ShowPre()
{
	Tree.PrintPre(cout);
}
void Application::ShowIn()
{
	Tree.PrintIn(cout);
}
void Application::ShowPost()
{
	Tree.PrintPost(cout);
}

void Application::Search()
{
	ItemType item;
	cout << "찾을 item의 이름을 입력하세요. ";
	item.SetNameByKB();

	bool found;
	Tree.SearchItem(item, found);
	if (found == true)
	{
		item.ShowAll();
	}
	else
		cout << "없어요 없어" << endl;
}