// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Vector2
{
private:
    T*      _data=nullptr;
    int     _size = 0;
    int     _capacity = 0;

public:

    Vector2() {

    }

    ~Vector2() {
        if (_data) {
            delete[] _data;
        }
    }

    void PUSHBACK(const T& value) {
        if (_size==_capacity) {
            //증설
            int NEWCAPACITY = _capacity * 1.5;
            if (NEWCAPACITY == _capacity) {
                NEWCAPACITY++;
            }
            RESERVE(NEWCAPACITY);//새로운 방 증설 
        }

        _data[_size] = value;
        _size++;

    }

    void RESERVE(const int& index) {
        _capacity = index;

        T* _newData = new T[_capacity];

        for (int i = 0; i < _size; i++) {
            _newData[i] = _data[i];
        }

        if (_data) {//기존 배열 존재시 
            delete[] _data;
            _data = _newData;
        }
    }

    T& operator[](const int& index) {
        return _data[index];
    }

    int size() {return _size;}
    int capacity() { return _capacity };

    void clear() {

        _size = 0;
    }
};



int main()
{
    vector<int> v;

    for (int i = 0; i < 100; i++) {
        v.push_back(i);
    }

    for (const int& ele : v) {
        cout << ele << "  ";
    }


}

