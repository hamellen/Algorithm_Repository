// Sort_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void swap(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;
}

void bubble_sort(vector<int>& arr) {//뒤에서 앞으로 범위를 줄여가며 큰숫자를 뒤로 보내기 

	for (int i = 0; i < arr.size() - 1; i++) {

		for (int j = arr.size() - 1 - i; j > 0; j--) {

			if (arr[j-1] > arr[j]) {
				swap(arr[j-1], arr[j]);
			}
		}
	}


}
void insert_sort(vector<int>& arr) {//오름차순 

	int i, j, temp;

	for (i = 1; i < arr.size(); i++) {
		temp = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < temp)//temp 보다 작은 지점 발견시 
				break;
			arr[j + 1] = arr[j];//if(arr[j]>= temp)//i위치의 값이 이전 인덱스 값보다 작으면 교환 
		}
		arr[j + 1] = temp;//temp보다 작은 최초의 지점의 다음 인덱스에 값 설정

	}
	
}
void selection_sort(vector<int>& arr) {

	for (int i = 0; i < arr.size() - 1; i++) {
		
		int temp = i;
		for (int j = i + 1; j < arr.size(); j++) {

			if (arr[temp] > arr[j]) {
				temp = j;
			}
		}

		if (temp != i) {
			swap(arr[i], arr[temp]);
		}
	}


}

void heap_sort(vector<int>& arr) {//힙정렬,힙의 특성 사용 O(NlogN)

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int num : arr) {
		pq.push(num);
	}

	arr.clear();

	while (pq.empty() == false) {

		arr.push_back(pq.top());
		pq.pop();
	}

}

void merge_result(vector<int>& v, int left,int mid, int right) {//실질적 정렬 

	int index_left = left;
	int index_right = mid + 1;
	vector<int> temp;

	while (index_left <= mid && index_right <= right) {

		if (v[index_left] <= v[index_right]) {
			temp.push_back(v[index_left]);
			index_left++;
		}
		else if (v[index_left] > v[index_right]) {
			temp.push_back(v[index_right]);
			index_right++;
		}
	}

	if (index_left > mid) {

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
void merge_sort(vector<int>& v,int left,int right) {//병합정렬 ,분할-정복-결합

	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	merge_sort(v, left, mid);
	merge_sort(v, mid+1, right);

	merge_result(v, left, mid, right);
}


void quick_sort(vector<int>& v) {

}

int main()
{

	vector<int> v = { 2,7,1,9,12,3};
	//selection_sort(v);
	//bubble_sort(v);
	//insert_sort(v);
	//heap_sort(v);
	//merge_sort(v, 0, v.size() - 1);


	for (int i = 0; i < v.size(); i++) {
		cout << v[i] ;
		if (i==v.size()-1) {
			break;
		}
		cout << "---";
	}


}