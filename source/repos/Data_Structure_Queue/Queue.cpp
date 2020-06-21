#include "Queue.h"

void FullQueue::print()
{
	cout << "FullQueue exception thrown." << endl;
}
void EmptyQueue::print()
{
	cout << "EmptyQueue exception thrown." << endl;
}

Queue::Queue()
{
	users = new UserType[MAXSIZE];
	nMaxQueue = MAXSIZE;
	Front = nMaxQueue - 1;
	Rear = nMaxQueue - 1;
}
Queue::Queue(int max)
{
	users = new UserType[max];
	nMaxQueue = max;
	Front = nMaxQueue - 1;
	Rear = nMaxQueue - 1;
}
Queue::~Queue()
{
	delete[] users;
}

bool Queue::isFull()
{
	if (Front - Rear == 1 || Rear - Front == nMaxQueue - 1)
		return 1;
	return 0;
}
bool Queue::isEmpty()
{
	if (Front == Rear)
		return 1;
	return 0;
}

void Queue::MakeEmpty()
{
	Front = nMaxQueue - 1;
	Rear = nMaxQueue - 1;
}

void Queue::EnQueue(UserType user)
{
	if (isFull())
		throw FullQueue();
	Rear = (Rear + 1) % nMaxQueue;
	users[Rear] = user;
}
void Queue::DeQueue(UserType& user)
{
	if (isEmpty())
		throw EmptyQueue();
	Front = (Front + 1) % nMaxQueue;
	user = users[Front];
}

void Queue::Print()
{
	if (Front > Rear)
	{
		for (int i = Front + 1; i < Rear; i++)
			users[i].PrintAll();
		for (int i = 0; i <= Rear; i++)
			users[i].PrintAll();
	}
	else
		for (int i = Front + 1; i <= Rear; i++)
			users[i].PrintAll();
	cout << endl;
}