#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int backtracking(string myString, int used[], string allPossible, int *pi);
vector<string> temp;
int main() {
    string myString;
    cin >> myString;
    sort(myString.begin(), myString.end());
    int used[myString.size()] = {0};
    string allPossible;
    int index = 0;

    backtracking(myString, used, allPossible, &index);

    cout << index << endl;
    for (auto it : temp)
    {
        cout << it << endl;
    }
    system("pause");
    return 0;
}

int backtracking(string myString, int used[], string allPossible, int *pi) {
    if (myString.size() == allPossible.size())
    {
        temp.push_back(allPossible);
        (*pi)++;
        return 1;
    }
    
    vector <int> repeated(26);
    int index = 0;
    for (int i = 0; i < myString.size(); i++)
    {
        if (!used[i])
        {
            index = myString[i] - 'a';
            repeated[index]++;
            if (repeated[index] > 1) continue;
            used[i] = 1;
            allPossible.push_back(myString[i]);
            backtracking(myString, used, allPossible, pi);
            used[i] = 0;
            allPossible.pop_back();
        }
        }
    }
