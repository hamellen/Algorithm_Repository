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

    void Merge(int u, int v) {//u�� v������ ����

        u = Find_boss(u);
        v = Find_boss(v);

        if (u == v) {//���� �θ� �� ������� 
            return;
       }

        parent[u] = v;
    }
private:
    vector<int> parent;
};

class DisjointSet {//���̰� ���� Ʈ���� ���̰� ���� Ʈ���� ��Ʈ �ؿ� ���� 
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

    void Merge(int u, int v) {//u�� v������ ����

        u = Find_boss(u);
        v = Find_boss(v);

        if (u == v) {//���� �θ� �� ������� 
            return;
        }


        if (rank[u]>rank[v]) {
            swap(u, v); //rank[u]<= rank[v] ���� 
        }

        parent[u] = v;//��ũ���� Ʈ���� ��ũ ���� Ʈ�� ������ �� 

        if (rank[u] == rank[v]) {//���̰� ������ ���� ������ �����Ƿ� �պ� �Ǵ� ���� ��ũ ��� 
            rank[v]++;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;//Ʈ���� ���� 
};//Ʈ���� ���̿� ���� ���� Ʈ���� ���� Ʈ���� 

struct Vertex {


};

vector<Vertex> vertices;
vector<vector<int>> adjacent;//���� ���


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
            edges.push_back(CostEdge{ cost,u,v });//�ϴ� ���� �Ǿ��ִ� ���� ���� 
        }
    }

    sort(edges.begin(), edges.end());//���� ���� ,�ڽ�Ʈ ���� �� ���� ���� �ͼ����� ���� 

    DisjointSet sets(vertices.size());

    for (CostEdge& edge : edges) {

        if (sets.Find_boss(edge.u) == sets.Find_boss(edge.v)) {//���� ������ ��ǽ� ��ȯ �߻� 
            continue;
        }

        sets.Merge(edge.u, edge.v);
        selected.push_back(edge);//�ּ� ���д� Ʈ���� ���� Ȯ�� 
        ret += edge.cost;
    }

    return ret;//�ּ� ���д� Ʈ���� ���� �ڽ�Ʈ 
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
