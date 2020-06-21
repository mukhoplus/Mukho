#include "UserType.h"

#define MAXSIZE 10

class FullStack
{
public:
	void print();
};
class EmptyStack
{
public:
	void print();
};

class Stack
{
private:
	int top;
	UserType* users;
public:
	Stack();
	~Stack();

	bool isFull();
	bool isEmpty();
	void Push(UserType user);
	UserType Pop();
	UserType Top();
	void Print();
};