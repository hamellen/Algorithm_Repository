// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex {
   

};

vector<Vertex> vertices;
vector<vector<int>> ad;
vector<bool> visited;
void CreateGraph() {

	vertices.resize(6);
	ad = vector<vector<int>>(6);

	ad[0].push_back(1);//인접 리스트
	ad[0].push_back(3);
	ad[1].push_back(0);
	ad[1].push_back(2);
	ad[1].push_back(3);
	ad[3].push_back(4);
	ad[5].push_back(4);


}

void dfs(int start) {//깊이 우선 탐색 

	visited[start] = true;//방문
	cout << start << endl;
	for (int i = 0; i < ad[start].size(); i++) {

		int next = ad[start][i];
		if (visited[next] == false) {// 방문하지 않으면 
			//cout << ad[start][i] << endl;
			dfs(next);
		}
	}

}

void dfs_all() {
	for (int i = 0; i < 6; i++) {
		if (visited[i] == false) {
			dfs(i);
		}
	}
}
void bfs(int start) {

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (q.empty() == false) {
		start = q.front();
		q.pop();

		cout << start << endl;//방문확인

		for (int there : ad[start]) {
			if (visited[there]) {//방문했을시 
				continue;
			}
			q.push(there);
			visited[there] = true;
		}
	}
}

int main()
{
	CreateGraph();
	visited = vector<bool>(6, false);
	bfs(0);


	//dfs_all();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
