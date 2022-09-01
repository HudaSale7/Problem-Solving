#include <iostream>
using namespace std;
int main() {
    long int num;
    cin >> num;
    if (num != 3 && num != 2)
    {
    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            cout << i << " ";
    }
    for (int i = 1; i <= num; i++)
    {
        if (i % 2 != 0)
            cout << i << " ";
    }
    cout << endl;
    } else
        cout << "NO SOLUTION";
    return 0;
}