#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long double num, base = 2;
    const unsigned int m = 1000000007;
    cin >> num;
    long long int sumBits = 0;
    for (long double i = 0; i < num; i++)
    {
        sumBits = sumBits + int(pow(base, i)) % m;
    }
    cout << sumBits
    system("pause");
    return 0;
}
