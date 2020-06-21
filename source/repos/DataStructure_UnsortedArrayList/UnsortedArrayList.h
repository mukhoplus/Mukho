#pragma once
#include "UserType.h"

class UnsortedArrayList
{
private:
	UserType* ArrayList;
	int Length;
	int CurPointer;
protected:
	int MAXSIZE = 10;
public:
	UnsortedArrayList();
	~UnsortedArrayList();

	void MakeEmpty();
	int GetLength();
	bool isFull();
	int Insert(UserType user);
	int Delete(UserType user);
	int Update(UserType user);
	int Get(UserType& user);

	void ResetIterator();
	int GetNextUser(UserType& user);

	int GetByBinarySearch(UserType& user);
};