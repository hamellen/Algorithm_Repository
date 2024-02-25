// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BubbleSort(vector<int>& v) {
	const int n = v.size();

	for (int i = 0; i < n-1; i++) {//몇번째 턴 
		for (int j = 0; j < n - 1-i; j++) {

			if (v[j] > v[j + 1]) {
				int temp = v[j + 1];
				v[j + 1] = v[j];
				v[j] = temp;
			}
		}
	}

}

void SelectionSort(vector<int>& v) {
	const int n = v.size();

	for (int i = 0; i < n - 1; i++) {
		int index_minimum = i;

		for (int j = i + 1; j < n; j++) {
			if (v[index_minimum] > v[j]) {
				index_minimum = j;
			}
		}
		int temp = v[index_minimum];
		v[index_minimum] = v[i];
		v[i] = temp;
	}

}


void InsertionSort(vector<int>& v) {

	const int n = v.size();

	for (int i = 1; i < n; i++) {
		int insertData = v[i];

		int index_insert;

		for (index_insert = i - 1; index_insert >= 0; index_insert--) {
			if (v[index_insert] > insertData) {
				v[index_insert + 1] = v[index_insert];
			}
			else
				break;
		}
		v[index_insert + 1] = insertData;
	}

}

void HeapSort(vector<int>& v) {

	priority_queue<int, vector<int>, greater<int>> pq;

	for (const int& ele : v) {
		pq.push(ele);
	}

	v.clear();

	while (pq.empty() == false) {

		v.push_back(pq.top());
		pq.pop();
	}

}// 우선순위 큐 

void MergeSort(vector<int>& v) {

	MergeSort(v);
	MergeSort(v);
}

int main()
{
	vector<int> v{ 0,6,2,7,12 };

	SelectionSort(v);

	for (const int& ele : v) {
		cout << ele << "\t";
	}

}

