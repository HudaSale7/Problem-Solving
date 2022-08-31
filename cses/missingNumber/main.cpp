#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int num;
    cin >> num;
    vector<int> myVector(num);
    vector<int> userVector(num - 1);

    for (int i = 0; i < userVector.size() ; i++)
    {
        cin >> userVector[i];
    }

    sort(userVector.begin(), userVector.end());

    for (int i = num - 1; i >= 0; i--)
    {
        myVector[i] = num--;
    }
    
    for (int i = 0; i < myVector.size(); i++)
    {
        if (myVector[i] != userVector[i]){
            cout << myVector[i] << endl;
            break;
        }
    }
    system("pause");
    return 0;
}