#include "BinarySearchTree.h"

void BinarySearchTree::insert(int value)
{

	Node* newNode = new Node();
	newNode->data = value;

	if (_root == nullptr) {//루트가 비어있을시 
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node) {//node가 없을때까지 

		parent = node;

		if (value < node->data) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	newNode->parent = parent;

	if (value < parent->data) {
		parent->left = newNode;
	}
	else {
		parent->right = newNode;
	}
}

void BinarySearchTree::Delete(int key)
{

}

void BinarySearchTree::Print_inorder(Node* node)//중위순회
{
	if (node == nullptr) {
		return;
	}

	Print_inorder(node->left);
	cout << node->data << endl;
	Print_inorder(node->right);
}

void BinarySearchTree::Print_preorder(Node* node)
{
	if (node == nullptr) {
		return;
	}
	cout << node->data << endl;
	Print_preorder(node->left);
	Print_preorder(node->right);
}

void BinarySearchTree::Print_postorder(Node* node)
{
	if (node == nullptr) {
		return;
	}

	Print_postorder(node->left);
	Print_postorder(node->right);
	cout << node->data << endl;

}

Node* BinarySearchTree::Search(Node* node,int key)
{

	if (node == nullptr || key == node->data) {
		return node;
	}
	
	if (key < node->data) {
		return Search(node->left, key);
	}
	else {
		return Search(node->right, key);
	}

}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left) {
		node = node->left;
	}

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
	{
		node = node->right;
	}

	return node;
}




