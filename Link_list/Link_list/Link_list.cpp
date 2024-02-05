// Link_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

template<typename T>
class Node
{
public:
	Node() {
		preNode = nullptr;
		data = T();
		postNode = nullptr;
	}
	
	Node(const T& value) {
		preNode = nullptr;
		data = value;
		postNode = nullptr;
	}
public:

	Node* preNode;
	T data;
	Node* postNode;

};


template<typename T>
class Iterator 
{
public:

	Iterator() { current_node = nullptr };

	Iterator(Node<T>* inputNode) {
		current_node = inputNode;
	}

	T& operator*() {
		current_node->data;
	}

	bool operator==(const Iterator& other) {
		return node == other.current_node;
	}

	bool operator!=(const Iterator& other) {
		return node != other.current_node;
	}

	Node<T>* current_node;

};

template<typename T>
class List 
{
public:
	List() 
	{
		size = 0;
		head = new Node<T>();
		tail = new Node<T>();
		head->postNode = tail;
		tail->preNode = head;
	}

	~List() {

		while (size > 0) { pop_back(); }
		delete head;
		delete tail;
	}

	void push_back(const T& value) 
	{
		AddNode(tail, value);
	}

	void pop_back() {

		RemoveNode(tail->preNode);
	}

	int size() { return size; }

	using iterator = Iterator<T>();

	Iterator begin() {
		return Iterator<T>(head->postNode);
	}

	Iterator end() {
		return Iterator<T>(tail);
	}

	Iterator insert(Iterator it, const T& value) {
		Node<T>* node = AddNode(it->current_node, value);
		return Iterator(node);
	}
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

	Node<T>* AddNode(Node<T>* before, const T& value)//Áß°£»ðÀÔ
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* preNode = before->preNode;

		preNode->postNode = newNode;
		newNode->preNode = preNode;
		newNode->postNode = before;
		before->preNode = newNode;
		size++;
		return newNode;
	}

	Node<T>* RemoveNode(Node<T>* deleteNode) 
	{
		Node<T>* preNode = deleteNode->preNode;
		Node<T>* postNode = deleteNode->postNode;

		preNode->postNode = postNode;
		postNode->preNode = preNode;

		delete deleteNode;

		size--;

		return postNode;
	}
};




int main()
{
	


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
