#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int binaryNumber(int num, string s, string a);
int main() {
    int num;
    cin >> num;
    string s;
    string a = {'0', '1'};
    binaryNumber(num, s, a);
    system("pause");
    return 0;
}

int binaryNumber(int num, string s, string a) {
    if (s.size() == num)
    {
        cout << s << endl;
        return 1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        s.push_back(a[i]);
        if(i == 1)
            binaryNumber(num, s, "10");
        else
            binaryNumber(num, s, "01");
        s.pop_back();
    }
} 
