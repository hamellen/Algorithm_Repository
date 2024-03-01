// Minimum Spanning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>


class NativeDisjointSet {
public:

    NativeDisjointSet(int n) : parent(n){
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Find_boss(int input) {
        if (input == parent[input]) {
            return input;
        }
        return Find_boss(parent[input]);
    }

    void Merge(int u, int v) {//u가 v밑으로 들어간다

        u = Find_boss(u);
        v = Find_boss(v);

        if (u == v) {//최종 부모 가 같을경우 
            return;
       }

        parent[u] = v;
    }
private:
    vector<int> parent;
};

class DisjointSet {//높이가 낮은 트리를 높이가 높은 트리의 루트 밑에 연결 
public:

    DisjointSet(int n) : parent(n),rank(n,1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Find_boss(int input) {
        if (input == parent[input]) {
            return input;
        }
        parent[input] = Find_boss(parent[input]);
        return parent[input];
    }

    void Merge(int u, int v) {//u가 v밑으로 들어간다

        u = Find_boss(u);
        v = Find_boss(v);

        if (u == v) {//최종 부모 가 같을경우 
            return;
        }


        if (rank[u]>rank[v]) {
            swap(u, v); //rank[u]<= rank[v] 성사 
        }

        parent[u] = v;//랭크작은 트리가 랭크 높은 트리 밑으로 들어감 

        if (rank[u] == rank[v]) {//높이가 같을시 이제 병합이 됐으므로 합병 되는 쪽의 랭크 상승 
            rank[v]++;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;//트리의 높이 
};//트리의 높이에 따라 낮은 트리를 높은 트리에 

struct Vertex {


};

vector<Vertex> vertices;
vector<vector<int>> adjacent;//인접 행렬


void CreateGraph() {
    vertices.resize(6);
    adjacent = vector<vector<int>>(6, vector<int>(6, -1));

    adjacent[0][1] = adjacent[1][0] = 15;
    adjacent[0][3] = adjacent[3][0] = 35;
    adjacent[1][2] = adjacent[2][1] = 5;
    adjacent[1][3] = adjacent[3][1] = 10;
    adjacent[3][5] = adjacent[5][3] = 10;
    adjacent[3][4] = adjacent[4][3] = 5;
    adjacent[4][5] = adjacent[5][4] = 5;
}

struct CostEdge {
    int cost;
    int u;
    int v;

    bool operator<(CostEdge& other) {
        return cost < other.cost;
    }
};

int Kruskal(vector<CostEdge>& selected) {

    int ret = 0;

    selected.clear();

    vector<CostEdge> edges;

    for (int u = 0; u < adjacent.size(); u++) {
        for (int v = 0; v < adjacent[u].size(); v++) {
            if (u > v) {
                continue;
            }
            
            int cost = adjacent[u][v];

            if (cost == -1) {
                continue;
            }
            edges.push_back(CostEdge{ cost,u,v });//일단 연결 되어있는 엣지 수집 
        }
    }

    sort(edges.begin(), edges.end());//오름 차순 ,코스트 작은 것 에서 높은 것순으로 정렬 

    DisjointSet sets(vertices.size());

    for (CostEdge& edge : edges) {

        if (sets.Find_boss(edge.u) == sets.Find_boss(edge.v)) {//같은 보스를 모실시 순환 발생 
            continue;
        }

        sets.Merge(edge.u, edge.v);
        selected.push_back(edge);//최소 스패닝 트리에 최종 확정 
        ret += edge.cost;
    }

    return ret;//최소 스패닝 트리의 최종 코스트 
}




int main()
{
    CreateGraph();

    vector<CostEdge> selected;
    int cost = Kruskal(selected);
    
    cout << cost << endl;
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
