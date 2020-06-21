#include "SortedArrayList.h"

SortedArrayList::SortedArrayList()
{
	ArrayList = new UserType[MAXSIZE];
	Length = 0;
	ResetList();
}
SortedArrayList::~SortedArrayList()
{
	if (ArrayList)
		delete[] ArrayList;
}

void SortedArrayList::MakeEmpty()
{
	Length = 0;
}
int SortedArrayList::GetLength()
{
	return Length;
}
bool SortedArrayList::isFull()
{
	if (Length > MAXSIZE - 1)
		return true;
	else
		return false;
}
int SortedArrayList::Insert(UserType user)
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
		for (int i = 0; i < Length; i++)
		{
			switch (ArrayList[i].ConpareById(user))
			{
			case LESS:
				if (i == Length - 1)
					ArrayList[Length] = user;
				break;
			case GREATER:
				for (int j = Length; j > i; j--)
					ArrayList[j] = ArrayList[j - 1];
				ArrayList[i] = user;
				break;
			case EQUAL:
				return -1;
				break;
			}
		}
	}

	Length++;
	return 1;
}
int SortedArrayList::Delete(UserType user)
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
int SortedArrayList::Update(UserType user)
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
int SortedArrayList::Get(UserType& user)
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

void SortedArrayList::ResetList()
{
	CurPointer = -1;
}
int SortedArrayList::GetNextUser(UserType& user)
{
	CurPointer++;
	if (CurPointer == MAXSIZE)
		return -1;
	user = ArrayList[CurPointer];

	return CurPointer;
}
int SortedArrayList::GetByBinarySearch(UserType& user)
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

void SortedArrayList::Sort()
{
	for (int i = 0; i < Length-1; i++)
		for (int j = i + 1; j < Length; j++)
			if (ArrayList[i].GetId() > ArrayList[j].GetId())
			{
				UserType temp;
				temp = ArrayList[i];
				ArrayList[i] = ArrayList[j];
				ArrayList[j] = temp;
			}
}