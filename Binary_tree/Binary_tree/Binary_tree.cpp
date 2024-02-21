// Binary_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;
#include "BinarySearchTree.h"
vector<int>numbers;

void BinarySearch(int search_int) {

    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) 
    {
        int mid = (left + right) / 2;

        if (search_int < numbers[mid]) {//찾으려는 숫자가 중간숫자보다 작을경우 
            right = mid-1;
        }
        else if (search_int > numbers[mid]) {//찾으려는 숫자가 중간숫자보다 클경우 
            left = mid + 1;
        }
        else {
            cout << "찾은숫자 :" << numbers[mid] << endl;
            break;
        }
    }

}



int main()
{
    numbers = vector<int>{ 1,8,15,23,32,44,56,63,81,91 };
    BinarySearch(81);



}

