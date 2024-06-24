// Tree_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
using namespace std;

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








int main()
{
    //NodeRef root=CreateTree();
    //PrintTree(root,0);
    //cout << " 높이 : " << GetHeight(root) << endl;

    priority_queue<int> pq_max;//최대 힙 
    priority_queue<int,vector<int>,greater<int>> pq_less;//최소  힙 

    pq_less.push(200);
    pq_less.push(300);
    pq_less.push(100);
    pq_less.push(700);

    while (pq_less.empty() == false) {

        int value = pq_less.top();
        pq_less.pop();

        cout << value << endl;
    }



}

