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


void MergeResult(vector<int>& v, int left, int mid, int right) {

	int index_left = left;
	int index_right = mid+1;
	vector<int> temp;

	while (index_left <= mid && index_right <= right) {//양쪽 배열 모두 기준 인덱스를 넘지 않았을 경우 

		if (v[index_left] <= v[index_right]) {
			temp.push_back(v[index_left]);
			index_left++;
		}
		else {
			temp.push_back(v[index_right]);
			index_right++;
		}
	}

	//한쪽 배열의 index가 기준 인덱스를 추가했을시 
	//왼쪽 끝났으면 오른쪽 배열 ,오른쪽 끝났으면 왼쪽 배열 

	if (index_left > mid) {//왼쪽 배열이 먼저 기준 인덱스를 넘어감 
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

