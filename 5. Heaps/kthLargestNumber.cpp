#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int cnt = 0;
        for (int num : nums)
        {
            if (cnt < k)
            {
                minHeap.push(num);
                cnt++;
            }
            else
            {
                if (num > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
        int ans = minHeap.top();
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
    cout << s.findKthLargest(nums, k) << endl;

    return 0;
}