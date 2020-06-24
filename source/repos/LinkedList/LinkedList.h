#include "ItemType.h"

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
	Node<T>* CurPointer;
	int length;
public:
	LinkedList();
	~LinkedList();
	
	void MakeEmpty();

	int GetLength();
	void ResetPointer();
	void NextPointer();
	bool isEmpty();
	void GetNextItem(T& item);

	int Insert(T& item);
	int Delete(T& item);
	int Update(T& item);
	int Get(T& item);
};

template <typename T>
LinkedList<T>::LinkedList()
{
	Head = NULL;
	CurPointer = NULL;
	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty();
}

template <typename T>
void LinkedList<T>::MakeEmpty()
{
	Node<T>* temp;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
	}
	length = 0;
}

template <typename T>
int LinkedList<T>::GetLength()
{
	return length;
}
template <typename T>
void LinkedList<T>::ResetPointer()
{
	CurPointer = NULL;
}
template <typename T>
void LinkedList<T>::NextPointer()
{
	if (CurPointer == NULL)
		CurPointer = Head;
	else
		CurPointer = CurPointer->next;
}
template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}
template<typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	NextPointer();
	item = CurPointer->data;
}
template <typename T>
int LinkedList<T>::Insert(T& item)
{
	ResetPointer();

	// 저장할 item을 노드에 저장
	Node<T>* node = new Node<T>;
	node->data = item;
	node->next = NULL;

	// 데이터가 없을 때
	if (!length)
		Head = node; // Head에 저장
	else
	{		
		while (1)
		{
			NextPointer();
			if (CurPointer->next == NULL)
				break;
		}
		CurPointer->next = node;
	}
	length++;
	return 1;
}
template <typename T>
int LinkedList<T>::Delete(T& item)
{
	bool success = false;
	Node<T>* pre;
	Node<T>* del;

	T temp; // 비교용 임시변수

	ResetPointer();
	if (Get(item) == 0) return 0;

	while (1)
	{
		pre = CurPointer;
		GetNextItem(temp);

		if (temp == item) // 지울 item을 찾았다
		{
			if (pre == NULL)
			{
				del = Head;
				Head = Head->next;
				delete del;
			}
			else
			{
				del = CurPointer;
				pre->next = CurPointer->next;
				delete del;
			}
			length--;
			success = true;
			break;
		}
	}
	return success;
}
template <typename T>
int LinkedList<T>::Update(T& item)
{
	Node<T>* location;
	location = Head;

	bool success = false;
	bool MoreToSearch = (location != NULL);

	while (MoreToSearch && !success)
	{
		if (item == location->data)
		{
			location->data = item;
			success = true;
		}
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}
	}

	return success;
}
template <typename T>
int LinkedList<T>::Get(T& item)
{
	Node<T>* location;
	location = Head;

	bool Found = false;
	bool MoreToSearch = (location != NULL);

	while (MoreToSearch && !Found)
	{
		if (item == location->data)
			Found = true;
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}
	}

	return Found;
}