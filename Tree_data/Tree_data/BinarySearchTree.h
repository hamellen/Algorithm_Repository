#pragma once

\
struct BST_Node {
	BST_Node* _parent = nullptr;
	BST_Node* _left=nullptr;
	BST_Node* _right=nullptr;
	int data;

};



class BinarySearchTree
{

private:
	BST_Node* root = nullptr;

public:

	void insert(int key);
};

