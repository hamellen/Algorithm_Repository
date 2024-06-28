// BinarySearchTree_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

int BinarySearch(vector<int>& data, int key) {

    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {

        int pivot = (left + right) / 2;

        if (data[pivot] == key) {// Å½»ö ¼º°ø 

            return pivot;
        }
        else if (data[pivot] < key) {

            left = pivot + 1;
        }
        else if (data[pivot] > key) {

            right = pivot - 1;
        }


    }

    return -1;
}



int main()
{
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
  
    

   
    cout << 1 << endl;
}


