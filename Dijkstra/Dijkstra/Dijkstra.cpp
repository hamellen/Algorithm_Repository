// Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

struct Node
{

};

vector<Node> nodes;
vector<vector<int>> ad;

void CreateGraph() {

	nodes.resize(6);
	ad = vector<vector<int>>(6,vector<int>(6,-1));

	ad[0][1] = 15;//0에서 1까지 가중치 15
	ad[0][3] = 35;
	ad[1][0] = 15;
	ad[1][2] = 5;
	ad[1][3] = 10;
	ad[3][4] = 5;
	ad[5][4] = 5;
}

void Dijikstra(int here) {//시작점에서 나머지 노드로 가는 최소의 가중치 

	struct NodeCost
	{
		int node;
		int cost;
	};

	list<NodeCost> visited;
	vector<int> best(6, INT32_MAX);//최소거리 

	visited.push_back(NodeCost{here,0});
	best[here] = 0;//시작점

	while (visited.empty()==false) {

		list<NodeCost>::iterator bestlt;
		int bestcost = INT_MAX;

		for (auto it = visited.begin(); it != visited.end(); it++) {

			
			const int cost = it->cost;

			if (bestcost > cost) {

				bestcost = cost;
				bestlt = it;
			}
		}

		int cost = bestlt->cost;
		here = bestlt->node;
		visited.erase(bestlt);

		if (best[here] < cost) {
			continue;
		}

		for (int there = 0; there < 6; there++) {
			if (ad[here][there] == -1) {//연결 되어있지 않음 
				continue;
			}

			int nextcost = best[here] + ad[here][there];

			if (nextcost >= best[there]) {
				continue;
			}

			best[there] = nextcost;

			visited.push_back(NodeCost{ there,nextcost });
		}
	}
}


int main()
{
	CreateGraph();

	Dijikstra(0);
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
