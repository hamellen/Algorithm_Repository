// dynamic_programing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int memory[50][50];//반복된 계산을 줄이기 위한 것 

int combination(int n, int r) {

    if (r == 0 || n == r) {
        return 1;
    }

    if (memory[n][r] != -1) {//메모리에 이미 저장된 값이 있을시 
        return memory[n][r];
    }
   


    return memory[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}
vector<int> seq;
int cache[10];
int LIS(vector<int>& input) {

    


}



int main()
{
    ::memset(cache, -1, sizeof(cache));
    seq = vector<int>{2,7,3,9,4};
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
