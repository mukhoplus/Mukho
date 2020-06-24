#include "ItemType.h"

template <typename T>
struct Node
{
	T data;
	Node* pre;
	Node* next;
};

template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	Node<T>* CurPointer;
	int length;
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void MakeEmpty();

	int GetLength();
	void ResetPointer();
	void PrePointer();
	void NextPointer();
	bool isEmpty();
	void GetPreItem(T& item);
	void GetNextItem(T& item);

	int Insert(T& item);
	int Delete(T& item);
	int Update(T& item);
	int Get(T& item);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	Head = NULL;
	CurPointer = NULL;
	length = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	MakeEmpty();
}

template <typename T>
void DoublyLinkedList<T>::MakeEmpty()
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
int DoublyLinkedList<T>::GetLength()
{
	return length;
}
template <typename T>
void DoublyLinkedList<T>::ResetPointer()
{
	CurPointer = NULL;
}
template <typename T>
void DoublyLinkedList<T>::PrePointer()
{
	if (CurPointer == NULL)
		CurPointer = Tail;
	else
		CurPointer = CurPointer->pre;;
}
template <typename T>
void DoublyLinkedList<T>::NextPointer()
{
	if (CurPointer == NULL)
		CurPointer = Head;
	else
		CurPointer = CurPointer->next;
}
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}
template<typename T>
void DoublyLinkedList<T>::GetPreItem(T& item)
{
	if (CurPointer == Head)
		cout << "Current Pointer is Head." << endl;
	PrePointer();
	item = CurPointer->data;
}
template<typename T>
void DoublyLinkedList<T>::GetNextItem(T& item)
{
	if (CurPointer == Tail)
		cout << "Current Pointer is Tail." << endl;
	NextPointer();
	item = CurPointer->data;
}
template <typename T>
int DoublyLinkedList<T>::Insert(T& item)
{
	ResetPointer();

	// 저장할 item을 노드에 저장
	Node<T>* node = new Node<T>;
	node->data = item;
	node->pre = NULL;
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
		node->pre = CurPointer;
		CurPointer->next = node;
		Tail = node;
	}
	length++;
	return 1;
}
template <typename T>
int DoublyLinkedList<T>::Delete(T& item)
{
	bool success = false;
	Node<T>* del;

	T temp; // 비교용 임시변수

	ResetPointer();
	if (Get(item) == 0) return 0;

	while (1)
	{
		GetNextItem(temp);

		if (temp == item) // 지울 item을 찾았다
		{
			if (CurPointer->pre == NULL) // 맨 앞이면
			{
				del = Head;
				Head = Head->next;
				Head->next->pre = NULL;
				delete del;
			}
			else
			{
				del = CurPointer;
				CurPointer->pre->next = CurPointer->next;
				if (del == Tail)
					Tail = CurPointer->pre;
				else
					CurPointer->next->pre = CurPointer->pre;
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
int DoublyLinkedList<T>::Update(T& item)
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
int DoublyLinkedList<T>::Get(T& item)
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