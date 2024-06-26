#include "BinarySearchTree.h"

void BinarySearchTree::insert(int key)
{
	BST_Node* newNode = new BST_Node();
	newNode->data = key;

	if (root == nullptr) {//루트 비어있을시 
		root = newNode;
	}

	BST_Node* node = root;
	BST_Node* parent = nullptr;

	while (node) {//node가 nullptr 일경우 삽입할 장소 찾음 ,while  중단 

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
