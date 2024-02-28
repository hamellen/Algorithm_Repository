// Minimum Spanning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>

struct Node {
    Node* leader;
};

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

class DisjointSet {
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
            swap(u, v);
        }

        parent[u] = v;

        if (rank[u] == rank[v]) {
            rank[v]++;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;//트리의 높이 
};
int main()
{
    DisjointSet teams(1000);

    teams.Merge(10, 1);

    int teamid = teams.Find_boss(1);
    cout << teamid << endl;
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
