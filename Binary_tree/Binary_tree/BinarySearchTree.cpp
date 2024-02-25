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

	if (_root == nullptr) {//��Ʈ�� ��������� 
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node) {//node�� ���������� 

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
	if (node==nullptr) {//node �������� ������ 
		return;
	}

	if (node->left==nullptr) {//�����ڽĸ� ������ 
		Replace(node, node->right);
	}
	else if (node->right == nullptr) {//������ �ڽĸ� ������ 
		Replace(node, node->left);
	}
	else {//���� �ڽ� �� ������ 
		Node* next = Next(node);
		node->data = next->data;
		Delete(next);
	}

}

void BinarySearchTree::Print_inorder(Node* node)//������ȸ
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
	else if (u == u->parent->left) {//�θ� ��尡 ���θ� ����� �����ϰ�� 
		u->parent->left = v;
	}
	else {//�θ� ��尡 ���θ� ����� ������ �ϰ�� 
		u->parent->right = v;
	}

	if (v) {//v�� �θ� u�� �θ�� ����
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

	while (parent && node == parent->right) {//�����Ͻ� ���� ���� ��� �Ǻ� 
		node = parent;
		parent = parent->parent;
	}


	return parent;
}



