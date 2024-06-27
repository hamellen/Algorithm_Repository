#pragma once

struct Node {

	Node* _parent = nullptr;
	Node* _left = nullptr;
	Node* _right = nullptr;
	int data;
};


class BinarySearchTree
{
private:

	Node* root = nullptr;
public:

	void pre_order(Node* node);
	void in_order(Node* node);
	void post_order(Node* node);
	void insert(int key);




};

