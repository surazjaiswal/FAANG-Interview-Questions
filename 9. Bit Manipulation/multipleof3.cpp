#include <bits/stdc++.h>
using namespace std;

bool solve(int n)
{
    if (n == 0)
        return true;

    int oddCnt = 0, evenCnt = 0;
    bool toggle = false; // staring with odd count - > if toggle is oddCnt will be counted else evenCnt will counted
    while (n != 0)
    {
        if (n & 1 && toggle)
        {
            if (toggle)
                oddCnt++;
            else
                evenCnt++;
        }
        toggle = !toggle;
        n >>= 1;
    }

    if (abs(oddCnt - evenCnt) % 3 == 0)
        return true;
    return false;
}

bool solve(string str)
{

    int n = str.length();
    int oddCnt = 0, evenCnt = 0;
    bool toggle = false; // staring with odd count - > if toggle is oddCnt will be counted else evenCnt will counted
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            if (toggle)
                oddCnt++;
            else
                evenCnt++;
        }
        toggle = !toggle;
    }

    if (abs(oddCnt - evenCnt) % 3 == 0)
        return true;
    return false;
}

int main()
{

    // for binary string input
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }

    // for number input
    int n;
    cin >> n;
    if (solve(n))
        cout << "true" << endl;
    else
        cout << "false";
    return 0;
}