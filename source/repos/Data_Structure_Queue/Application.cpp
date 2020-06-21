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
				EnQueueUser();
				break;
			case 2:
				DeQueueUser();
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
	catch (FullQueue)
	{
		cout << "FullQueue exception thrown." << endl;
	}
	catch (EmptyQueue e)
	{
		e.print();
	}
}

int Application::GetCommand()
{
	cout << "------ Queue ------" << endl;
	cout << "-- 1. EnQueue User" << endl;
	cout << "-- 2. DeQueue User" << endl;
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

int Application::EnQueueUser()
{
	if (!tQueue.isFull())
	{
		UserType user;
		user.SetAllFromKB();

		tQueue.EnQueue(user);
		return 1;
	}
	return 0;
}
int Application::DeQueueUser()
{
	if (!tQueue.isEmpty())
	{
		UserType user;
		tQueue.DeQueue(user);
		user.PrintAll();

		return 1;
	}
	return 0;
}

int Application::CheckEmpty()
{
	if (tQueue.isEmpty())
	{
		cout << "Queue is Empty." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Queue is not Empty." << endl << endl;
		return 0;
	}
}int Application::CheckFull()
{
	if (tQueue.isFull())
	{
		cout << "Queue is Full." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Queue is not Full." << endl << endl;
		return 0;
	}
}

void Application::TestEmptyException()
{
	UserType user;

	while (1)
		tQueue.DeQueue(user);
}
void Application::TestFullException()
{
	UserType user;

	while (1)
	{
		user.SetId(" ");
		user.SetName(" ");
		tQueue.EnQueue(user);
	}
}

void Application::PrintAllUser()
{
	tQueue.Print();
}