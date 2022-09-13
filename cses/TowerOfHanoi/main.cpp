#include <iostream>
#include <cmath>
using namespace std;

void moveDisks(int count, int start, int finish, int temp);
int main() {
    double numOfDisks;
    cin >> numOfDisks;
    int start = 1;
    int end = 3;
    int temp = 2;
    long long int numSteps = pow(2, numOfDisks) - 1;
    cout << numSteps << endl;
    moveDisks(numOfDisks, start, end, temp);
    system("pause");
    return 0;
}

void moveDisks(int count, int start, int end, int temp) {
    while (count > 0)
    {
        moveDisks(count - 1, start, temp, end);
        cout << start << " " << end << endl;
        count--;
        int swap = start;
        start = temp;
        temp = swap;
    }
}