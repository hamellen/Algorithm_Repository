// Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node {

	Node(const string& input) {
		data = input;
	}
	string data;
	vector<NodeRef> children;
};

NodeRef CreateTree() {//트리 생성

	NodeRef root = make_shared<Node>("개발실");
	{
		NodeRef node = make_shared<Node>("디자인");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("전투");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("경제");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("스토리");
			node->children.push_back(leaf);
		}
	}


}

void PrintTree(NodeRef root) {//재귀

	cout << root->data << endl;

	for (NodeRef child : root->children) {
		PrintTree(child);
	}

}

int GetHeight(NodeRef root) {

	int height = 1;

	for (NodeRef& child : root->children) {//자식노드가 존재할시 

		height = max(height, GetHeight(child) + 1);

	}



	return height;
}

template<typename T>
class PriorityQueue 
{
public:

	void push(const T& value) {

		_heap.push_back(value);

		int now = _heap.size() - 1;

		while (now>0)
		{
			int parent = (now - 1) / 2;

			if (_heap[now] < _heap[parent]) {
				break;
			}

			::swap(_heap[now], _heap[parent]);

			now = parent;
		}

	}

	void pop() {

		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true) 
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			if (left >= _heap.size()) {//리프에 도달한 경우 
				break;
			}

			int next = now;

			if (_heap[next] < _heap[left]) {
				next = left;
			}

			if (right < _heap.size() && _heap[next] < _heap[right]) {
				next = right;
			}

			if (next == now) {
				break;
			}

			::swap(_heap[now], _heap[next]);//값 바꾸ㅏ치기 
			now = next;
		}

	}

	T& top() {
		return _heap[0];
	}

	bool empty() {
		return _heap.empty();
	}

private:
	 
	vector<T> _heap = {};
};

int main()
{
	
	
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
