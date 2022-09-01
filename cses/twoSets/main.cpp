#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long int num;
    cin >> num;
    long long int sum = 0;
    sum = num * (num + 1) / 2;
    if (sum % 2 != 0)
    {
        cout <<"NO" << endl;
        return 0;
    }
    sum /= 2; 
    vector<unsigned int> set1(num);
    vector<unsigned int> set2;
    for (long int i = num - 1; i >= 0; i--)
    {
        set1[i] = num--;
    }
    long long int sumOfMax = 0;
    while (sumOfMax != sum)
    {
        long long int diff;
        diff = sum - sumOfMax; 
        if (diff < set1.size())
        {
            sumOfMax += diff;
            set2.push_back(diff);
            auto it = set1.begin();
            set1.erase(it + (diff - 1));
        } else {
            int temp = set1[set1.size() - 1];
            sumOfMax += temp;
            set2.push_back(temp);
            set1.pop_back();
        }
    }
    cout <<"YES" << endl;
    cout << set1.size() << endl;
    for (auto i : set1)
    {
        cout << i << " ";
    }
    cout << endl << set2.size() << endl;
    for (auto i : set2)
    {
        cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
    }