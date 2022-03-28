#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k, x;
    cin >> k >> x;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (k--)
        {
            pq.push({abs(nums[i] - x), nums[i]});
        }
        else
        {
            int diff = abs(nums[i] - x);
            if (diff < pq.top().first)
            {
                pq.pop();
                pq.push({diff, nums[i]});
            }
        }
    }

    vector<int> ans;
    while (pq.size())
    {
        int num = pq.top().second;
        ans.push_back(num);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}