#include "Queue.h"

class Application
{
private:
	int cmd;
	Queue tQueue;
public:
	Application();
	~Application();

	void Run();
	int GetCommand();
	int EnQueueUser();
	int DeQueueUser();
	int CheckEmpty();
	int CheckFull();
	void TestEmptyException();
	void TestFullException();
	void PrintAllUser();
};