#include "Stack.h"

class Application
{
private:
	int cmd;
	Stack tStack;
public:
	Application();
	~Application();

	void Run();
	int GetCommand();
	int PushUser();
	int PopUser();
	int CheckEmpty();
	int CheckFull();
	void TestEmptyException();
	void TestFullException();
	void PrintAllUser();
};