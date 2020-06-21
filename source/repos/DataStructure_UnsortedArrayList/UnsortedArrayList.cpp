#include "UnsortedArrayList.h"

UnsortedArrayList::UnsortedArrayList()
{
	ArrayList = new UserType[MAXSIZE];
	Length = 0;
	ResetIterator();
}
UnsortedArrayList::~UnsortedArrayList()
{
	if (ArrayList)
		delete[] ArrayList;
}

void UnsortedArrayList::MakeEmpty()
{
	Length = 0;
}
int UnsortedArrayList::GetLength()
{
	return Length;
}
bool UnsortedArrayList::isFull()
{
	if (Length > MAXSIZE - 1)
		return true;
	else
		return false;
}
int UnsortedArrayList::Insert(UserType user)
{
	if (Length == 0)
	{
		ArrayList[Length] = user;
	}
	else
	{
		if (Length >= MAXSIZE)
		{
			MAXSIZE++;

			UserType* temp;
			temp = new UserType[Length];
			for (int i = 0; i < Length; i++)
				temp[i] = ArrayList[i];

			ArrayList = new UserType[Length + 1];
			for (int i = 0; i < Length; i++)
				ArrayList[i] = temp[i];
			delete[] temp;
		}
		ArrayList[Length] = user;
	}

	Length++;
	return 1;
}
int UnsortedArrayList::Delete(UserType user)
{
	for (int i = 0; i < Length; i++)
	{
		if (ArrayList[i].GetId() == user.GetId())
		{
			for (int j = i; j < Length - 1; j++)
				ArrayList[j] = ArrayList[j + 1];
			Length--;
			return 1;
		}
	}
	return 0;
}
int UnsortedArrayList::Update(UserType user)
{
	for (int i = 0; i < Length; i++)
	{
		if (ArrayList[i].GetId() == user.GetId())
		{
			ArrayList[i].SetAllFromKB();
			return 1;
		}
	}
	return 0;
}
int UnsortedArrayList::Get(UserType& user)
{
	for (int i = 0; i < Length; i++)
	{
		if (ArrayList[i].GetId() == user.GetId())
		{
			user = ArrayList[i];
			return 1;
		}
	}
	return 0;
}

void UnsortedArrayList::ResetIterator()
{
	CurPointer = -1;
}
int UnsortedArrayList::GetNextUser(UserType& user)
{
	CurPointer++;
	if (CurPointer == MAXSIZE)
		return -1;
	user = ArrayList[CurPointer];

	return CurPointer;
}
int UnsortedArrayList::GetByBinarySearch(UserType& user)
{
	int first = 0;
	int last = Length - 1;
	bool found = false;

	while (first <= last && !found)
	{
		int mid = (first + last) / 2;
		switch (user.ConpareById(ArrayList[mid]))
		{
		case LESS:
			last = mid - 1;
			break;
		case GREATER:
			first = mid + 1;
			break;
		case EQUAL:
			user = ArrayList[mid];
			found = 1;
			return found;
			break;
		}
	}
	return 0;
}