// https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.length();

    // removing all the digits
    if (n == k)
    {
        return "0";
    }

    // defining monotonic stack
    stack<char> stk;
    for (char ch : num)
    {
        while (k && stk.size() && (int(stk.top()) > int(ch)))
        {
            stk.pop();
            k--;
        }
        stk.push(ch);
    }

    while (k--)
    {
        stk.pop(); // all last left k digits will be removed, monotonic
    }

    stack<char> new_stk;
    while (stk.size())
    {
        new_stk.push(stk.top());
        stk.pop();
    }

    while (new_stk.top() == '0' && new_stk.size() != 1)
    {
        new_stk.pop();
    }

    string ans = "";
    while (new_stk.size())
    {
        ans += new_stk.top();
        new_stk.pop();
    }
    return ans;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    string num;
    cin >> num;

    int k;
    cin >> k;

    cout << removeKdigits(num, k) << endl;

    return 0;
}