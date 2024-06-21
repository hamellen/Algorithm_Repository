// Linear_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
class Node {

public:

    Node(): _data(T()) {

    }

    Node(const T& value) {
        _data = value;
    }


private:
    Node* previous=nullptr;
    Node* next = nullptr;
    T _data;
};

template<typename T>
class List {

private:

    Node<T>* head;
    Node<T>* tail;
    int _size = 0;

    Node<T>* AddNode(Node<T>* before, const T& value) {

        Node<T>* newNode = new Node(value);
        Node<T>* previous = before->previous;

        previous->next = newNode;
        newNode->previous = previous;
        newNode->next = before;
        before->previous = newNode;

        _size++;

        return newNode;
    }

    Node<T>* DeleteNode(Node<T>* todelete) {

        Node<T>* _previous = todelete->previous;
        Node<T>* _next = todelete->next;

        _previous->next = _next;
        _next->previous = _previous;

        delete todelete;

        _size--;

        return _next;
    }

public:

    List() {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->previous = head;
    }

    ~List() {

        while (_size > 0) {
            pop_back();
        }

        delete head;
        delete tail;
    }

    void pop_back() {
        DeleteNode(tail->previous);
    }
    

    void push_back(const T& value) {

        AddNode(tail, value);
    }

    int size() {
        return _size;
    }

};

template<typename T>
class Stack {

public:

    void pop() {

        container.pop_back();
    }

   
    T& top() {
        return container.back();
    }

    void push(const T& value) {

        container.push_back(value);
    }

    bool empty() { return container.empty(); }
    int size() { return constainer.size(); }
private:
    vector<T> container;
   
};


template<typename T>
class Vector 
{
public:
    Vector() {
        _data = new T[];
    }

    ~Vector() {
        if (_data) {
            delete[] _data;
        }
    }

    void push_back(const T& value) {

        if (_size == _capacity) {
            int newCapacity = static_cast<int>(1.5 * _capacity);
            if (newCapacity == _capacity) {
                newCapacity++;
            }
            reserve(newCapacity);
        }

        _data[_size] = value;
        _size++;

    }

    void reserve(int capacity) {

        _capacity = capacity;

        T* newData = new T[_capacity];

        for (int i = 0; i < _size; i++) {
            newData[i] = _data[i];
        }
        if (_data) {
            delete[] _data;
        }

        _data = _newData;
    }

    T& operator[](int index) {
        return _data[index];
    }

    int size() {
        return _size;
    }

    int capacity() {
        return _capacity;
    }

    void clear() {

        if (_data) {
            delete[] _data;
            _data = new T[_capacity];
        }
        _size = 0;
    }
private:
    T* _data=nullptr;
    int _size = 0;
    int _capacity = 0;

};



int main()
{
   





}


