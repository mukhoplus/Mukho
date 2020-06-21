#include "Application.h"

Application::Application()
{
	cmd = -1;
}
Application::~Application()
{}

void Application::Run()
{
	try {
		while (1)
		{
			cmd = GetCommand();

			switch (cmd)
			{
			case 1:
				PushUser();
				break;
			case 2:
				PopUser();
				break;
			case 3:
				CheckEmpty();
				break;
			case 4:
				CheckFull();
				break;
			case 5:
				TestEmptyException();
				break;
			case 6:
				TestFullException();
				break;
			case 7:
				PrintAllUser();
				break;
			case 0:
				return;
			default:
				GetCommand();
				break;
			}
		}
	}
	catch (FullStack)
	{
		cout << "FullStack exception thrown." << endl;
	}
	catch (EmptyStack e)
	{
		e.print();
	}
}

int Application::GetCommand()
{
	cout << "------ Stack ------" << endl;
	cout << "-- 1. Push User" << endl;
	cout << "-- 2. Pop User" << endl;
	cout << "-- 3. Check Empty" << endl;
	cout << "-- 4. Check Full" << endl;
	cout << "-- 5. Test Empty Exception" << endl;
	cout << "-- 6. Test Full Exception" << endl;
	cout << "-- 7. Print All User" << endl;
	cout << "-- 0. Back" << endl;
	cout << "----------------------------" << endl;
	cout << "-- Choose number you run : ";
	cin >> cmd;

	return cmd;
}

int Application::PushUser()
{
	if (!tStack.isFull())
	{
		UserType user;
		user.SetAllFromKB();

		tStack.Push(user);
		return 1;
	}
	return 0;
}
int Application::PopUser()
{
	if (!tStack.isEmpty())
	{
		UserType user;
		user = tStack.Pop();
		user.PrintAll();

		return 1;
	}
	return 0;
}

int Application::CheckEmpty()
{
	if (tStack.isEmpty())
	{
		cout << "Stack is Empty." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Stack is not Empty." << endl << endl;
		return 0;
	}
}int Application::CheckFull()
{
	if (tStack.isFull())
	{
		cout << "Stack is Full." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Stack is not Full." << endl << endl;
		return 0;
	}
}

void Application::TestEmptyException()
{
	UserType user;

	while (1)
		user = tStack.Pop();
}
void Application::TestFullException()
{
	UserType user;

	while (1)
	{
		user.SetId(" ");
		user.SetName(" ");
		tStack.Push(user);
	}
}

void Application::PrintAllUser()
{
	tStack.Print();
}