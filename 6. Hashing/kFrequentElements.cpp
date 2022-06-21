#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        vector<pair<int, int>> vt;

        for (auto it : mp)
            vt.push_back({it.first, it.second});

        sort(vt.begin(), vt.end(), cmp);
        vector<int> ans;

        for (auto it : vt)
        {
            if (k--)
                ans.push_back(it.first);
            else
                break;
        }

        return ans;
    }

    bool static cmp(pair<int, int> v1, pair<int, int> v2)
    {
        return v1.second > v2.second;
    }
};

class compare
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        for (auto it : mp)
            pq.push({it.first, it.second});

        vector<int> ans;
        while (pq.size() && k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution s;
    s.topKFrequent(nums, k);

    return 0;
}