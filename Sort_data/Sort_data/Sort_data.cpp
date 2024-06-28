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

void bubble_sort(vector<int>& arr) {//�ڿ��� ������ ������ �ٿ����� ū���ڸ� �ڷ� ������ 

	for (int i = 0; i < arr.size() - 1; i++) {

		for (int j = arr.size() - 1 - i; j > 0; j--) {

			if (arr[j-1] > arr[j]) {
				swap(arr[j-1], arr[j]);
			}
		}
	}


}
void insert_sort(vector<int>& arr) {//�������� 

	int i, j, temp;

	for (i = 1; i < arr.size(); i++) {
		temp = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < temp)//temp ���� ���� ���� �߽߰� 
				break;
			arr[j + 1] = arr[j];//if(arr[j]>= temp)//i��ġ�� ���� ���� �ε��� ������ ������ ��ȯ 
		}
		arr[j + 1] = temp;//temp���� ���� ������ ������ ���� �ε����� �� ����

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

void heap_sort(vector<int>& arr) {//������,���� Ư�� ��� O(NlogN)

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
void merge_sort(vector<int>& arr) {//�������� ,����-����-����





}

int main()
{

	vector<int> v = { 2,7,1,9,12,3};
	//selection_sort(v);
	//bubble_sort(v);
	//insert_sort(v);
	//heap_sort(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] ;
		if (i==v.size()-1) {
			break;
		}
		cout << "---";
	}


}