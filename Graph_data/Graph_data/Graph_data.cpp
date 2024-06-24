// Graph_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

struct VertexCost {

	
	int vertex;
	int cost;

};

struct Vertex {


};

vector<Vertex> v;
vector<vector<int>> adjacent;
vector<bool> visited;


//void dfs(int start) {
//
//	if (visited[start]) {
//		return;
//	}
//	visited[start] = true;
//	cout <<"Ž�� ����: "<< start << endl;
//
//	if (v[start].edges.size() > 0) {//�ٸ� ��� ���� ��Ʈ�� �����Ұ�� 
//		
//		auto it = find(v.begin(), v.end(), *(v[start].edges[0]));
//		dfs(it - v.begin());
//	}
//	
//}

//adjacent = vector<vector<int>>(6);//��������Ʈ

void dfs(int start) {//��Ϳ��

	if (visited[start]) {
		return;
	}
	visited[start] = true;
	cout << start << endl;

	if (adjacent[start].size() > 0) {

		for (const int& ele : adjacent[start]) {
			dfs(ele);
		}
	}

}

void bfs(int start) {//�ڷᱸ�� queue �� ����� 

	vector<int> parents(6, -1);//������ ���� �߰ߵǾ����� 
	vector<int> distance(6, 0);//����������� �Ÿ� 

	
	queue<int> q;
	q.push(start);
	visited[start] = true;

	parents[start] = start;

	while (q.empty()==false) {

		start = q.front();
		q.pop();

		cout << start << endl;
		for (const int& ele : adjacent[start]) {
			if (visited[ele] == true) {
				continue;
			}
			q.push(ele);
			visited[ele] = true;
			parents[ele] = start;
			distance[ele] = distance[start] + 1;
		}
	}


}

//���ͽ�Ʈ��-bfs������ ����ġ ���� �߰�,�� �������� ���µ� �ּ� �Ÿ� ����,���� ��� ���

void Dijikstra(int start) {//���� ���� 

	list<VertexCost> discovered;
	vector<int> minimal(6, INT32_MAX);//������ �ּҰŸ� 

	discovered.push_back(VertexCost{start,0});
	minimal[start] = 0;

	while (discovered.empty() == false) {

		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;//�Ϻη� �ִ�ġ ����

		for (auto it = discovered.begin(); it != discovered.end(); it++) {

			if (it->cost < bestCost) {
				bestCost = it->cost;
				bestIt = it;
			}
		}

		int cost = bestIt->cost;
		start = bestIt->vertex;
		discovered.erase(bestIt);

		if (minimal[start] < cost) {
			continue;
		}

		for (int there = 0; there < 6; there++) {

			if (adjacent[start][there] == -1) {
				continue;
			}

			int nextcost = minimal[start] + adjacent[start][there];
			if (nextcost >= minimal[there]) {
				continue;
			}
			minimal[there] = nextcost;

			discovered.push_back(VertexCost{ there,nextcost });
		}

	}


}

int main()
{
	v.resize(6);
	adjacent = vector<vector<int>>(6,vector<int>(6,-1));
	visited = vector<bool>(6, false);
	
	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[4][5] = 5;

	



}

