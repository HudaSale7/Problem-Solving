#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size;
    long int counter = 0;
    cin >> size;
    long int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    if (size == 1)
    {
        cout << counter << endl;
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            counter += (arr[i] - arr[i + 1]);
            arr[i + 1] = arr[i];
        }
    }
    cout << counter << endl;
    return 0;
}