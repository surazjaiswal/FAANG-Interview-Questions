#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n)
    {
        char str[20];
        generateBrackets(str, 0, 0, 0, n);
        return ans;
    }

    void generateBrackets(char *str, int i, int open, int close, int n)
    {
        // base case
        if (i == n * 2)
        {
            str[i] = '\0';
            ans.push_back(str);
            return;
        }
        // recursion case
        if (open < n)
        {
            str[i] = '(';
            generateBrackets(str, i + 1, open + 1, close, n);
        }
        if (close < open)
        {
            str[i] = ')';
            generateBrackets(str, i + 1, open, close + 1, n);
        }
        return;
    }
};

void generateP(int open, int close, int i, int n, char *str, vector<string> &ans)
{
    if (i == n * 2)
    {
        str[i] = '\0';
        ans.push_back(str);
        return;
    }

    if (open < n)
    {
        str[i] = '(';
        generateP(open + 1, close, i + 1, n, str, ans);
    }

    if (close < open)
    {
        str[i] = ')';
        generateP(open, close + 1, i + 1, n, str, ans);
    }
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    char str[30];
    vector<string> ans;
    generateP(0, 0, 0, n, str, ans);

    // Solution s;
    // ans = s.generateParenthesis(n);
    
    for (auto it : ans)
        cout << it << endl;

    return 0;
}