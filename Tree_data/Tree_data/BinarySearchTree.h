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

public:
	BST_Node* root = nullptr;

public:
	void pre_order(BST_Node* node);
	void in_order(BST_Node* node);
	void post_order(BST_Node* node);
	void insert(int key);

	void Pre();
	void In();
	void Post();

	
};

