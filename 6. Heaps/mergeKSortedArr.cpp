// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : kArrays)
    {
        for (int i : it)
        {
            pq.push(i);
        }
    }
    vector<int> nums;
    while (!pq.empty())
    {
        nums.push_back(pq.top());
        pq.pop();
    }

    return nums;
}

int main()
{
    return 0;
}