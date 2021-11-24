#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isOdd(int a) { return a % 2; }
bool isOdd2(char a) { return (isdigit(a) and ((a - '0') % 2)) or (isalpha(a) and (toupper(a) - 'A') % 2); }

int main()
{
    vector<int> v = {1, 3, 5};
    int t[] = {1, 2, 3};
    string s = "13579";
    cout << boolalpha << all_of(v.begin(), v.end(), isOdd) << endl;
    cout << boolalpha << all_of(t, t + 3, isOdd) << endl;
    cout << boolalpha << all_of(s.begin(), s.end(), isOdd2) << endl;
}