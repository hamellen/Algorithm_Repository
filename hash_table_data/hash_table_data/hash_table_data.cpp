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

	//충돌문제 해결 
	//선형조사법- 해쉬함수로 배출한값이 충돌이 발생하면 +1
	//이차조사법 - (해쉬함수값+i)^2
	//체이닝- 해쉬함수로 배출한값이 충돌이 발생하면 발생할위치에 이차원 배열 행태로 또 다른 배열 생성 
}


//map : 레드 블랙트리 -이진검색트리로써 O(logN)
//hash_map :  O(1)
int main()
{
	   
}

