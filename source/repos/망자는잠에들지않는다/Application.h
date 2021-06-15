#include "User.h"

class Application {
private:
	int cmd;
	list<User> UserList;
	list<User>::iterator iter;
public:
	Application();
	~Application() {};

	void Run();
	int getCommand();
	void Insert();
	void Delete();
	void Update();
	void Search();
	void Print();
	void ResetIterator();
};