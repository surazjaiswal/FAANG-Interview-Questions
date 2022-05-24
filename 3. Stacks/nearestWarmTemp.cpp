#include <bits/stdc++.h>
using namespace std;

void getTemps(vector<int> temp)
{
    int n = temp.size();

    stack<int> stk;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && temp[stk.top()] < temp[i])
        {
            ans[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }

    for (int i : ans)
    {
        cout << i << " ";
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    getTemps(nums);

    return 0;
}