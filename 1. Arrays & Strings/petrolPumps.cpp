#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> gas(n), cost(n);

    for (int i = 0; i < n; i++)
        cin >> gas[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    int net = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            net += gas[i] - cost[i]; // calculating net gas left after completing a successfile cycle
            curr += gas[i] - cost[i]; // calculating curr gas left, deciding factor for moving to next station
            if (curr < 0)
            {
                // this means that current position will not lead to complete cycle
                curr = 0;
                start = i + 1; // moving to next starting position
            }
        }
        // if net is negative, this means that it is not possible to reach end from any possition with any feul left

    if (net < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << start << endl;
    }

    return 0;
}