#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    string palindrome;
    cin >> palindrome;
    vector<int> repeatedStr(36);
    int index;
    int flag = 0;
    int odd = 0;
    for (int i = 0; i < palindrome.size(); i++)
    {
        index = palindrome[i] - 'A';
        repeatedStr[index]++;
    }
    for (int i = 0; i < repeatedStr.size(); i++)
    {
        if (repeatedStr[i] % 2 != 0)
            flag++;
        if (flag > 1)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }
    for (int i = 0; i < repeatedStr.size(); i++)
    {
        if (repeatedStr[i] % 2 == 0 && repeatedStr[i] != 0)
        {
            cout << string(repeatedStr[i] / 2, 'A' + i);
        }
        if (repeatedStr[i] % 2 != 0)
        {
            odd = repeatedStr[i];
            index = i;
        }
    }
    if (odd)
        cout << string(odd, 'A' + index);
    
    for (int i = repeatedStr.size() - 1; i >= 0; i--)
    {
        if (repeatedStr[i] % 2 == 0 && repeatedStr[i] != 0)
        {
            cout << string(repeatedStr[i] / 2, 'A' + i);
        }
    }
    cout << endl;
    system("pause");
    return 0;
}