// hash_table_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct USER {
	int id;
	string name;
};

void TestHash() {

	vector<USER> users;

	users.resize(100);

	int id = 234662;
	int key = id % 100;

	users[key] = USER{ id,"JDH" };

	//�浹���� �ذ� 
	//���������- �ؽ��Լ��� �����Ѱ��� �浹�� �߻��ϸ� +1
	//��������� - (�ؽ��Լ���+i)^2
	//ü�̴�- �ؽ��Լ��� �����Ѱ��� �浹�� �߻��ϸ� �߻�����ġ�� ������ �迭 ���·� �� �ٸ� �迭 ���� 
}


//map : ���� ��Ʈ�� -�����˻�Ʈ���ν� O(logN)
//hash_map :  O(1)
int main()
{
	   
}

