#pragma once
#include "UserType.h"

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class SortedSinglyLinkedList
{
private:
	Node<T>* Head;
	Node<T>* iterator;
	int Length;
public:
	SortedSinglyLinkedList();
	~SortedSinglyLinkedList();
	SortedSinglyLinkedList(const SortedSinglyLinkedList<T>& LinkedList_);
	SortedSinglyLinkedList<T> operator=(const SortedSinglyLinkedList<T>& LinkedList_);

	void MakeEmpty();
	int GetLength();
	bool isEmpty();
	int Insert(T& user);
	int Delete(T& user);
	int Update(T& user);
	int Get(T& user);

	void ResetList();
	void GetNextUser(T& user);
	void GetCurUser(T& user);
	int Front(T& user);
	void GoToNextUser();
	bool isLastIterator();
};

template<typename T>
SortedSinglyLinkedList<T>::SortedSinglyLinkedList()
{
	Head = NULL;
	iterator = NULL;
	Length = 0;
}
template<typename T>
SortedSinglyLinkedList<T>::~SortedSinglyLinkedList()
{
	MakeEmpty();
}
template<typename T>
SortedSinglyLinkedList<T>::SortedSinglyLinkedList(const SortedSinglyLinkedList<T>& LinkedList_)
{
	Head = NULL;
	iterator = NULL;

	if (LinkedList_.Head == NULL)
		return;
	else
	{
		this->Length = LinkedList_.Length;

		Node<T>* Node_ = new Node<T>;
		Node<T>* iter;
		this->Head = Node_;

		Node_->data = LinkedList_.Head->data;
		iter = LinkedList_.Head->next;

		while (iter != NULL)
		{
			Node_->next = new Node<T>;
			Node_ = Node_->next;
			Node_->data = iter->data;
			iter = iter->next;
		}
		Node_->next = NULL;
	}
}
template<typename T>
SortedSinglyLinkedList<T> SortedSinglyLinkedList<T>::operator=(const SortedSinglyLinkedList<T>& LinkedList_)
{
	MakeEmpty();
	SortedSinglyLinkedList<T> temp(LinkedList_);

	Head = NULL;
	iterator = NULL;

	if (LinkedList_.Head == NULL)
		return *this;
	else
	{
		this->Length = LinkedList_.Length;

		Node<T>* Node_ = new Node<T>;
		Node<T>* iter;
		Head = Node_;
		Node_->data = LinkedList_.Head->data;
		iter = LinkedList_.Head->next;

		while (iter != NULL)
		{
			Node_->next = new Node<T>;
			Node_ = Node_->next;
			Node_->data = iter->data;
			iter = iter->next;
		}
		Node_->next = NULL;
	}
	return temp;
}

template<typename T>
void SortedSinglyLinkedList<T>::MakeEmpty()
{
	Node<T>* temp;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
	}
	Length = 0;
}
template<typename T>
int SortedSinglyLinkedList<T>::GetLength()
{
	return Length;
}
template<typename T>
bool SortedSinglyLinkedList<T>::isEmpty()
{
	if (Length = 0)
		return true;
	else
		return false;
}
template<typename T>
int SortedSinglyLinkedList<T>::Insert(T& user)
{
	ResetList();

	Node<T>* Node_ = new Node<T>;
	Node<T>* pre; // 이전 노드 가리킬 포인터

	T temp;
	bool Found = false;

	Node_->data = user;
	Node_->next = NULL;

	if (!Length) // 기존 데이터가 없을 경우
	{
		Head = Node_;
		Found = true;
	}
	else
	{
		while (1)
		{
			pre = iterator;

			GetNextUser(temp);
			if (iterator->data == Node_->data) // 중복
				break;

			if (iterator->data > Node_->data) // 넣을 데이터가 비교 값 보다 앞일 경우
			{
				if (pre == NULL) // 첫번째에 삽입
				{
					Node_->next = iterator;
					Head = Node_;
					Found = true;
					break;
				}
				else
				{
					Node_->next = iterator;
					pre->next = Node_;
					Found = true;
					break;
				}
			}

			if (iterator->next == NULL) // 마지막에 삽입
			{
				iterator->next = Node_;
				Found = true;
				break;
			}
		}
	}

	if (Found == true)
	{
		Length++;
		return 1;
	}
	else
		return 0;
}
template<typename T>
int SortedSinglyLinkedList<T>::Delete(T& user)
{
	Node<T>* pre;
	Node<T>* del;
	T temp;
	ResetList();
	bool Found = false;

	if (Get(user) == 0)
		return 0;

	while (1)
	{
		pre = iterator;
		GetNextUser(temp);
		if (temp == user)
		{
			if (pre == NULL) // 삭제 값이 맨 처음에 있을 때
			{
				del = Head;
				Head = Head->next;
				delete del;
				Found = true;
				break;
			}
			else
			{
				del = iterator;
				pre->next = iterator->next; // 전 포인터와 다음 포인터를 연결
				delete del;
				Found = true;
				break;
			}
		}
		if (iterator->next == NULL)
			break;
	}

	if (Found)
	{
		Length--;
		return 1;
	}
	else
		return 0;
}
template<typename T>
int SortedSinglyLinkedList<T>::Update(T& user)
{
	Node<T>* location;
	location = Head;
	bool Found = false;
	bool MoreToSearch = (location != NULL);

	while (MoreToSearch && !Found) // 리스트의 끝이 아니면서, 아직 못찾았을 경우
	{
		if (user == location->data)
		{
			location->data = user;
			Found = true;
		}
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}
	}
	if (Found)
		return 1;
	else
		return 0;
}
template<typename T>
int SortedSinglyLinkedList<T>::Get(T& user)
{
	Node<T>* location;
	bool Found = false;
	bool MoreToSearch = false;

	location = Head;
	MoreToSearch = (location != NULL);

	while (MoreToSearch && !Found)
	{
		if (user == location->data)
		{
			user = location->data;
			Found = true;
		}
		else
		{
			location = location->next;
			MoreToSearch = (location != NULL);
		}
	}
	if (Found)
		return 1;
	else
		return 0;
}

template<typename T>
void SortedSinglyLinkedList<T>::ResetList()
{
	iterator = NULL;
}
template<typename T>
void SortedSinglyLinkedList<T>::GetNextUser(T& user)
{
	if (iterator == NULL)
		iterator = Head;
	else
		iterator = iterator->next;
	user = iterator->data;
}
template<typename T>
void SortedSinglyLinkedList<T>::GetCurUser(T& user)
{
	if (iterator == NULL)
		iterator = Head;
	user = iterator->data;
}
template<typename T>
int SortedSinglyLinkedList<T>::Front(T& user)
{
	if (!isEmpty())
	{
		user = Head->data;
		iterator = Head->next;
		return 1;
	}
	else
		return 0;
}
template<typename T>
void SortedSinglyLinkedList<T>::GoToNextUser()
{
	iterator = iterator->next;
}
template<typename T>
bool SortedSinglyLinkedList<T>::isLastIterator()
{
	if (iterator == NULL)
		return true;
	else
		return false;
}