#pragma once

using namespace std;
#include<iostream>
struct  Node
{
	Node* parent=nullptr;
	Node* left=nullptr;
	Node* right=nullptr;
	int data;
};


class BinarySearchTree
{
public:

	void insert(int value);
	void Delete(int key);

	void Print_inorder(Node* node);
	void Print_preorder(Node* node);
	void Print_postorder(Node* node);

	Node* Search(Node* node,int key);
	Node* Min(Node* node);
	Node* Max(Node* node);
	
private:

	Node* _root = nullptr;

};

