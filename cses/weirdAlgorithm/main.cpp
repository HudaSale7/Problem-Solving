#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long num;
    cin >> num;
    cout << num << " ";
    while (num != 1)
    {
        if (num % 2 == 0) 
            num /= 2;
        else {
            num *= 3;
            num++;
        }
    cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}