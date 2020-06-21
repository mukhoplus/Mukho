#pragma once
#include "UserType.h"

class SortedArrayList
{
private:
	UserType* ArrayList;
	int Length;
	int CurPointer;
protected:
	int MAXSIZE = 10;
public:
	SortedArrayList();
	~SortedArrayList();

	void MakeEmpty();
	int GetLength();
	bool isFull();
	int Insert(UserType user);
	int Delete(UserType user);
	int Update(UserType user);
	int Get(UserType& user);

	void ResetList();
	int GetNextUser(UserType& user);

	int GetByBinarySearch(UserType& user);

	void Sort();
};