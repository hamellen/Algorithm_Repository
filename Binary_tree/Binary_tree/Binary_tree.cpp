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

        if (search_int < numbers[mid]) {//ã������ ���ڰ� �߰����ں��� ������� 
            right = mid-1;
        }
        else if (search_int > numbers[mid]) {//ã������ ���ڰ� �߰����ں��� Ŭ��� 
            left = mid + 1;
        }
        else {
            cout << "ã������ :" << numbers[mid] << endl;
            break;
        }
    }

}



int main()
{
    numbers = vector<int>{ 1,8,15,23,32,44,56,63,81,91 };
    BinarySearch(81);



}

