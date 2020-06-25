#include "ItemType.h"

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root;
public:
	BinarySearchTree();
	~BinarySearchTree();

	bool isEmpty();
	bool isFull();
	void MakeEmpty();
	int GetLength();
	void InsertItem(T item);
	void DeleteItem(T item);
	void SearchItem(T& item, bool& found);

	void PrintPre(ostream& out);
	void PrintIn(ostream& out);
	void PrintPost(ostream& out);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

}
template <typename T>
bool BinarySearchTree<T>::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}
template <typename T>
bool BinarySearchTree<T>::isFull()
{
	Node* item;
	try
	{
		item = new Node;
		delete item;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}
template <typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);
}
template <typename T>
int BinarySearchTree<T>::GetLength()
{
	return CountNodes(root);
}

template <typename T>
void BinarySearchTree<T>::InsertItem(T item)
{
	Insert(root, item);
}
template <typename T>
void BinarySearchTree<T>::DeleteItem(T item)
{
	Delete(root, item);
}
template <typename T>
void BinarySearchTree<T>::SearchItem(T& item, bool& found)
{
	Search(root, item, found);
}

template <typename T>
void BinarySearchTree<T>::PrintPre(ostream& out)
{
	PrintPreorder(root, cout);
}
template <typename T>
void BinarySearchTree<T>::PrintIn(ostream& out)
{
	PrintInorder(root, cout);
}
template <typename T>
void BinarySearchTree<T>::PrintPost(ostream& out)
{
	PrintPostorder(root, cout);
}

template <typename T>
void MakeEmptyTree(Node<T>*& root)
{
	root = NULL;
}
template <typename T>
int CountNodes(Node<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;
}
template <typename T>
void Insert(Node<T>*& root, T item)
{
	if (root == NULL)
	{
		root = new Node<T>;
		root->left = NULL;
		root->right = NULL;
		root->data = item;
	}
	else if (root->data > item)
		Insert(root->left, item);
	else if (root->data < item)
		Insert(root->right, item);
}
template <typename T>
void GetPredecessor(Node<T>* root, T& item)
{
	while (root->right != NULL)	
		root = root->right;
	item = root->data;
}
template <typename T>
void DeleteNode(Node<T>*& root)
{
	T item;
	Node<T>* tempPtr;
	tempPtr = root;

	if (root->left == NULL)
	{
		root = root->right;
		delete tempPtr;
	}
	else if (root->right == NULL)
	{
		root = root->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);
		root->data = item;
		Delete(root->left, item);
	}
}
template <typename T>
void Delete(Node<T>*& root, T item)
{
	if (item < root->data)
		Delete(root->left, item);
	else if (item > root->data)
		Delete(root->right, item);
	else
		DeleteNode(root);
}
template <typename T>
void Search(Node<T>* root, T& item, bool& found)
{
	if (root == NULL)
		found = false;
	else if (item.GetName() < root->data.GetName())
		Search(root->left, item, found);
	else if (item.GetName() > root->data.GetName())
		Search(root->right, item, found);
	else
	{
		item = root->data;
		found = true;
	}
}

template <typename T>
void PrintPreorder(Node<T>* tree, ostream& out)
{
	if (tree != NULL)
	{
		out << tree->data;
		PrintPreorder(tree->left, out);
		PrintPreorder(tree->right, out);
	}
}
template <typename T>
void PrintInorder(Node<T>* tree, ostream& out)
{
	if (tree != NULL)
	{
		PrintInorder(tree->left, out);
		out << tree->data;
		PrintInorder(tree->right, out);
	}
}
template <typename T>
void PrintPostorder(Node<T>* tree, ostream& out)
{
	if (tree != NULL)
	{
		PrintPostorder(tree->left, out);
		PrintPostorder(tree->right, out);
		out << tree->data;
	}
}