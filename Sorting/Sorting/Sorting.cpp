// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BubbleSort(vector<int>& v) {
	const int n = v.size();

	for (int i = 0; i < n-1; i++) {//���° �� 
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

}// �켱���� ť 


void MergeResult(vector<int>& v, int left, int mid, int right) {

	int index_left = left;
	int index_right = mid+1;
	vector<int> temp;

	while (index_left <= mid && index_right <= right) {//���� �迭 ��� ���� �ε����� ���� �ʾ��� ��� 

		if (v[index_left] <= v[index_right]) {
			temp.push_back(v[index_left]);
			index_left++;
		}
		else {
			temp.push_back(v[index_right]);
			index_right++;
		}
	}

	//���� �迭�� index�� ���� �ε����� �߰������� 
	//���� �������� ������ �迭 ,������ �������� ���� �迭 

	if (index_left > mid) {//���� �迭�� ���� ���� �ε����� �Ѿ 
		while (index_right <= right) {
			temp.push_back(v[index_right]);
			index_right++;
		}
	}
	else {
		while (index_left <= mid) {
			temp.push_back(v[index_left]);
			index_left++;
		}
	}

	for (int i = 0; i < temp.size(); i++) {
		v[left + i] = temp[i];
	}
}

void MergeSort(vector<int>& v,int left,int right) {

	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;

	MergeSort(v,left,mid);
	MergeSort(v,mid+1,right);

	MergeResult(v, left, mid, right);
}

int partition(vector<int>& v, int left, int right) {
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {

		while (pivot >= v[low] && low <= right) {
			low++;
		}
		while (pivot <= v[high] && high >= left + 1) {
			high--;
		}
		if (low < high) {
			swap(v[low], v[high]);
		}
	}
	swap(v[left], v[high]);
	return high;
}


void QuickSort(vector<int>& v, int left, int right)
{
	if (left > right) {
		return;
	}

	int pivot = partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}


int main()
{
	

}

