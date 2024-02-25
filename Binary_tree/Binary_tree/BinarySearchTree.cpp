#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	_nil = new Node();
	_root = _nil;
}

BinarySearchTree::~BinarySearchTree()
{
	delete _nil;
}

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
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);

}

void BinarySearchTree::Delete(Node* node)
{
	if (node==nullptr) {//node 존재하지 않을시 
		return;
	}

	if (node->left==nullptr) {//왼쪽자식만 없을시 
		Replace(node, node->right);
	}
	else if (node->right == nullptr) {//오른쪽 자식만 없을시 
		Replace(node, node->left);
	}
	else {//양쪽 자식 다 있을시 
		Node* next = Next(node);
		node->data = next->data;
		Delete(next);
	}

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

void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr) {
		_root = v;
	}
	else if (u == u->parent->left) {//부모 노드가 조부모 노드의 왼쪽일경우 
		u->parent->left = v;
	}
	else {//부모 노드가 조부모 노드의 오른쪽 일경우 
		u->parent->right = v;
	}

	if (v) {//v의 부모를 u의 부모로 설정
		v->parent = u->parent;
	}


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

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right) {
		return Min(node->left);
	}

	Node* parent = node->parent;

	while (parent && node == parent->right) {//왼쪽일시 다음 값의 노드 판별 
		node = parent;
		parent = parent->parent;
	}


	return parent;
}




