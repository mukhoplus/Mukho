#include "Stack.h"

void FullStack::print()
{
	cout << "FullStack exception thrown." << endl;
}
void EmptyStack::print()
{
	cout << "EmptyStack exception thrown." << endl;
}

Stack::Stack()
{
	top = -1;
	users = new UserType[MAXSIZE];
}
Stack::~Stack()
{
	delete[] users;
}
bool Stack::isFull()
{
	if (top >= MAXSIZE - 1)
		return true;
	else
		return false;
}
bool Stack::isEmpty()
{
	if (top <= -1)
		return true;
	else
		return false;
}
void Stack::Push(UserType user)
{
	if (isFull())
		throw FullStack();
	else
	{
		top++;
		users[top] = user;
	}
}
UserType Stack::Pop()
{
	UserType temp;

	if (isEmpty())
		throw EmptyStack();
	else
	{
		temp = Top();
		top--;
		return temp;
	}
}
UserType Stack::Top()
{
	if (isEmpty())
		throw EmptyStack();
	else
		return users[top];
}
void Stack::Print()
{
	cout << "----- Stack -----" << endl;
	for (int i = top; i >= 0; i--)
		users[i].PrintAll();
	cout << endl;
}