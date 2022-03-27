#include <bits/stdc++.h>
using namespace std;

bool isPossible(int start_idx, vector<int> &gas, vector<int> &cost)
{
    int idx = start_idx, cnt = 0, curr_gas = 0;
    int m = gas.size();
    curr_gas = gas[idx];
    while (cnt < m)
    {
        if (curr_gas >= cost[idx])
        {
            curr_gas = curr_gas - cost[idx];
            idx++;
            if (idx == m)
            {
                idx = idx % m;
            }
            curr_gas = curr_gas + gas[idx];
        }
        else
        {
            return false;
        }
        cnt++;
    }
    return true;
}

int main()
{

    int n;
    cin >> n;

    vector<int> gas(n), cost(n);

    for (int i = 0; i < n; i++)
        cin >> gas[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i < n; i++)
    {
        if (gas[i] != 0)
        {
            if (isPossible(i, gas, cost))
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}