#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

void BinarySearchTree::pre_order(Node* node)
{
	if (node == nullptr) {
		return;
	}
	cout << node->data << endl;
	pre_order(node->_left);
	pre_order(node->_right);
}

void BinarySearchTree::in_order(Node* node)
{
	if (node == nullptr) {
		return;
	}
	in_order(node->_left);
	cout << node->data << endl;
	in_order(node->_right);
}

void BinarySearchTree::post_order(Node* node)
{
	if (node == nullptr) {
		return;
	}
	post_order(node->_left);
	post_order(node->_right);
	cout << node->data << endl;
}

void BinarySearchTree::insert(int key)
{
	Node * newNode = new Node();
	newNode->data = key;

	if (root == nullptr) {//��Ʈ ��������� 
		root = newNode;
	}

	Node* node = root;
	Node* parent = nullptr;

	while (node) {//node�� nullptr �ϰ�� ������ ��� ã�� ,while  �ߴ� 

		parent = node;
		if (node->data < key) {

			//parent = node;
			node = parent->_right;

		}
		else if (node->data > key) {
			//parent = node;
			node = parent->_left;

		}
	}
	newNode->_parent = parent;

	if (parent->data < key) {
		parent->_right = newNode;
	}
	else if (parent->data > key) {
		parent->_left = newNode;
	}
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(get_root(), key);
	if (deleteNode) {
		Delete(deleteNode);
	}
	

}

void BinarySearchTree::Delete(Node* node)
{

	if (node->_left == nullptr) {//�����ҷ��� ����� ������ ������� 
		Replace(node, node->_right);
	}
	else if (node->_right == nullptr) {//�����ҷ��� ����� �������� ������� 
		Replace(node, node->_left);
	}
	else {//�����ҷ��� ����� ������ ������� 
		Node* next = Next(node);//�����ҷ��� ����� ���� �� ��尡������ 
		node->data = next->data;//�����ҷ��� ����� ���� ���� �� ����� �� �Է� 
		Delete(next);//���� �� ��� ���� 
	}
}

void BinarySearchTree::Replace(Node* u, Node* v)//u�� ����Ʈ���� v�� ����Ʈ���� ��ü ,u�� ��� �ڸ��� v�� ��ü 
{
	if (u->_parent == nullptr) {//u�� ��Ʈ����Ͻ� 
		root = v;
	}else if (u == u->_parent->_left) {
		u->_parent->_left = v;
	}
	else if(u == u->_parent->_right){
		u->_parent->_right = v;
	}

	if (v) {
		v->_parent = u->_parent;
	}
	delete u;
}

Node* BinarySearchTree::get_root()
{
	return root;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || node->data == key) {
		return node;
	}
	
	if (key < node->data) {
		return Search(node->_left, key);
	}
	else if (key > node->data) {
		return Search(node->_right, key);
	}


	return node;
}

Node* BinarySearchTree::Search2(Node* node, int key)
{
	while (node && node->data != key) {

		if (node->data < key) {
			node = node->_right;
		}
		else if (node->data > key) {
			node = node->_left;
		}

	}


	return node;
}

Node* BinarySearchTree::Min(Node* _node)
{
	Node* parent = nullptr;
	Node* node = _node;



	while (node) {
		parent = node;
		node = parent->_left;
	}
	return parent;
}

Node* BinarySearchTree::Max(Node* _node)
{
	Node* parent = nullptr;
	Node* node = _node;

	while (node) {
		parent = node;
		node = parent->_right;
	}


	return parent;
}

Node* BinarySearchTree::Next(Node* _node)
{
	if (_node->_right) {//right��� �����ҽ�-right ��� Ʈ���ȿ��� ���� ���� ����� ã�� 
		return Min(_node->_right);
	}

	Node* parent = _node->_parent;

	while (parent && _node == parent->_right) {//�ڽ��� �θ��� ������ ����� ���� �ڽ��� �θ𺸴� ũ�ٴ� ���� �ǹ� 

		_node = parent;
		parent = parent->_parent;
	}


	return parent;
}

//void BinarySearchTree::PRE()
//{
//	pre_order(root);
//}
//
//void BinarySearchTree::IN()
//{
//	in_order(root);
//}
//
//void BinarySearchTree::POST()
//{
//	post_order(root);
//}
