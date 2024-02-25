#pragma once

using namespace std;
#include<iostream>

enum class Color {
	Red = 0,
	Black = 1
};

struct  Node
{
	Node* parent=nullptr;
	Node* left=nullptr;
	Node* right=nullptr;
	int data;
	Color color = Color::Black;
};


class BinarySearchTree
{
public:

	BinarySearchTree();
	~BinarySearchTree();

	void insert(int value);
	void Delete(int key);
	void Delete(Node* node);

	void Print_inorder(Node* node);
	void Print_preorder(Node* node);
	void Print_postorder(Node* node);
	void Replace(Node* u, Node* v);


	Node* Search(Node* node,int key);
	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);
private:

	Node* _root = nullptr;
	Node* _nil = nullptr;
};

