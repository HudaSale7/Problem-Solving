#include <iostream>
using namespace std;
long long int fac(long long int num) {
    if (num != 0)
        return num * fac(num - 1);
    else
        return 1;
}
int main() {
    long long int num;
    long long int facNum;
    long long int numOfZeros = 0;
    int counter = -1;
    cin >> num;
    facNum = fac(num);
    while (numOfZeros == 0)
    {
        numOfZeros = facNum % 10;
        facNum /= 10;
        counter++;
    }
    cout << counter << endl;
    return 0;
}