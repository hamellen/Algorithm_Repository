// Tree_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <vector>
#include <list>
#include <string>
#include <queue>
#include<iostream>
using namespace std;
#include "BinarySearchTree.h"

using NodeRef = shared_ptr<struct Node>;

struct Node {

    Node() {

    }
    Node(const string& _data) :data(_data) {

    }


    string data;
    vector<NodeRef> children;
};

NodeRef CreateTree() {

    NodeRef root = make_shared<Node>("개발실");
    {
        NodeRef node_1 = make_shared<Node>("디자인팀");
        root->children.push_back(node_1);
        {
            NodeRef leaf_1= make_shared<Node>("전투");
            NodeRef leaf_2 = make_shared<Node>("경제");
            NodeRef leaf_3 = make_shared<Node>("스토리");

            node_1->children.push_back(leaf_1);
            node_1->children.push_back(leaf_2);
            node_1->children.push_back(leaf_3);
        }
        NodeRef node_2 = make_shared<Node>("프로그래밍팀");
        root->children.push_back(node_2);
        {

        }
        NodeRef node_3 = make_shared<Node>("아트팀");
        root->children.push_back(node_3);
        {

        }


    }


    return root;
}

void PrintTree(NodeRef root,int depth) {//왼쪽에서 오른쪽으로 

    for (int i = 0; i < depth; i++) {
        cout << "-";
    }


    cout << root->data << endl;

    for (NodeRef& node : root->children) {
        PrintTree(node,depth+1);
    }



}

int GetHeight(NodeRef root) {//재귀용법

    int height = 1;

    for (NodeRef& node : root->children) {

        height = max(height, GetHeight(node) + 1);

    }

    return height;

}

int BinarySearch(vector<int>& data, int key) {

    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {

        int pivot = (left + right) / 2;

        if (data[pivot] == key) {// 탐색 성공 

            return pivot;
        }
        else if (data[pivot] < key) {

            left = pivot + 1;
        }
        else if (data[pivot] > key) {

            right = pivot - 1;
        }


    }

    return -1;
}



int main()
{
    //NodeRef root=CreateTree();
    //PrintTree(root,0);
    //cout << " 높이 : " << GetHeight(root) << endl;
    //priority_queue<int> pq_max;//최대 힙 
    //priority_queue<int,vector<int>,greater<int>> pq_less;//최소  힙 

    BinarySearchTree bst;

    bst.insert(3);
    bst.insert(8);
    bst.insert(9);
    bst.insert(1);

    cout << bst.root->data << endl;

    //bst.in_order(bst.root);

}

