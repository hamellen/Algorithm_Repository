// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


void TestHash() {

    struct User {
        int usetid = 0;
        string username;
    };

    vector<User> users;
    users.resize(1000);

    const int userid = 123456789;
    int index = userid % 1000;//아주 기본적인 해쉬 알고리즘 


    users[index] = User{ userid,"JDH" };

    cout << users[index].username << endl;
}

void TestHashTableChaining() {
    struct User {
        int userid = 0;
        string username;
    };

    vector<vector<User>> users;
    users.resize(1000);

    const int userid = 123456789;
    int index = userid % 1000;//아주 기본적인 해쉬 알고리즘 

    users[index].push_back(User{ userid,"JDH" });//충돌 발생시 체인 기법

    for (const User& user : users[index]) {
        if (user.userid == userid) {
            cout << user.username << endl;
            break;
        }
    }
}
int main()
{
    TestHash();
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
