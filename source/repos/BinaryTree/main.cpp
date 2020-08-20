/*
... iss Crew
... Made By Mukho
... 2020-08-20 THU
... Binary Tree practice
*/

#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* root;
	Node* left;
	Node* right;
public:
	Node() : data(-1), root(nullptr), left(nullptr), right(nullptr) {};
	Node(int x) : data(x), root(nullptr), left(nullptr), right(nullptr) {};
	Node(int x, Node* l, Node* r) : data(x), root(nullptr), left(l), right(r) {
		if (l != nullptr)
			l->root = this;
		if (r != nullptr)
			r->root = this;
	};
	~Node() {};

	void SetLeft(Node* node) { this->left = node; }
	void SetRight(Node* node) { this->right = node; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	int GetData() { return data; }
};

void Preorder(Node* node); // 전위
void Inorder(Node* node); // 중위
void Postorder(Node* node); // 후위

/*
			6
		2
			
	4 
			5
		1
			3

*/
int main() {
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4, node1, node2); // root
	Node* node5 = new Node(5);
	Node* node6 = new Node(6);
	node1->SetLeft(node3);
	node1->SetRight(node5);
	node2->SetRight(node6);

	cout << "전위(Preorder) : "; // 4 1 3 5 2 6
	Preorder(node4);
	cout << endl;
	cout << "중위(Inorder) : "; // 3 1 5 4 2 6
	Inorder(node4);
	cout << endl;
	cout << "후위(Postorder) : "; // 3 5 1 6 2 4
	Postorder(node4);
	cout << endl;

	return 0;
}

void Preorder(Node* node) {
	if (node == nullptr)
		return;

	cout << node->GetData() << ' ';
	Preorder(node->GetLeft());
	Preorder(node->GetRight());
}
void Inorder(Node* node) {
	if (node == nullptr)
		return;

	Inorder(node->GetLeft());
	cout << node->GetData() << ' ';
	Inorder(node->GetRight());
}
void Postorder(Node* node) {
	if (node == nullptr)
		return;

	Postorder(node->GetLeft());
	Postorder(node->GetRight());
	cout << node->GetData() << ' ';
}