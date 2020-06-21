#include "UserType.h"

#define MAXSIZE 10

class FullQueue
{
public:
	void print();
};
class EmptyQueue
{
public:
	void print();
};

class Queue
{
private:
	int Front;
	int Rear;
	int nMaxQueue;
	UserType* users;
public:
	Queue();
	Queue(int max);
	~Queue();

	bool isFull();
	bool isEmpty();
	void MakeEmpty();
	void EnQueue(UserType user);
	void DeQueue(UserType& user);
	void Print();
};
