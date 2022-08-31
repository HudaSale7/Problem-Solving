#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string someLetter;
    int count = 1;
    int maxRepeat = 1;
    cin >> someLetter;

    for (int i = 0; i < someLetter.size() - 1; i++)
    {
        if (someLetter[i] == someLetter[i+1])
        {
            count++;
            if (maxRepeat < count)
            {
                maxRepeat = count;
            }
        }
        else {
            count = 1;
        }
    }
    cout << maxRepeat << endl;
    system("pause");
    return 0;
}