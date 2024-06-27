#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
void BinarySearchTree::pre_order(BST_Node* node)//���� 
{
	if (node == nullptr) {
		return;
	}
	cout << node->data << endl;
	pre_order(node->_left);
	pre_order(node->_right);

}

void BinarySearchTree::in_order(BST_Node* node)//���� 
{
	if (node == nullptr) {
		return;
	}
	in_order(node->_left);
	cout << node->data << endl;
	in_order(node->_right);
}

void BinarySearchTree::post_order(BST_Node* node)//����
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
	BST_Node* newNode = new BST_Node();
	newNode->data = key;

	if (root == nullptr) {//��Ʈ ��������� 
		root = newNode;
	}

	BST_Node* node = root;
	BST_Node* parent = nullptr;

	while (node) {//node�� nullptr �ϰ�� ������ ��� ã�� ,while  �ߴ� 

		if (node->data < key) {

			parent = node;
			node = parent->_right;

		}
		else if (node->data > key) {
			parent = node;
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

void BinarySearchTree::Pre()
{
	pre_order(root);
}

void BinarySearchTree::In()
{
	in_order(root);
}

void BinarySearchTree::Post()
{
	post_order(root);
}
