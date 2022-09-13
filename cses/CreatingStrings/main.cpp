#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;
int backtracking(string nums, int used[], string allPossible);
long long int index = 0;
vector<string> temp;
int main() {
    string myString;
    cin >> myString;
    int used[myString.size()] = {0};
    string allPossible;
    backtracking(myString, used, allPossible);
    cout << index << endl;
    for (auto it : temp)
    {
        cout << it << endl;
    }
    system("pause");
    return 0;
}

int backtracking(string myString, int used[], string allPossible) {
    if (myString.size() == allPossible.size())
    {
        cout << allPossible << endl;
        return 1;
    }
    for (int i = 0; i < myString.size(); i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            allPossible.push_back(myString[i]);
            backtracking(myString, used, allPossible);
            used[i] = 0;
            allPossible.pop_back();
        }
        }
    }
