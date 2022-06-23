// https://leetcode.com/problems/power-of-two/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n > 0)
        {
            if ((n & (n - 1)) > 0)
            {
                return false;
            }
            return true;
        }
        return false;
    }
};

int main()
{

    int n;
    cin >> n;

    int cnt = __builtin_popcount(n);
    if (cnt == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}