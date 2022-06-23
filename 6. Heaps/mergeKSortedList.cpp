// https://leetcode.com/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return {};
        if (lists.size() == 1)
            return lists[0];

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> q;
        for (auto it : lists)
        {
            ListNode *node = it;
            while (node)
            {
                q.push(make_pair(node->val, node));
                node = node->next;
            }
        }
        if (q.empty())
            return {};
        auto node = q.top();
        ListNode *ans = node.second, *temp;
        temp = ans;
        q.pop();
        while (!q.empty())
        {
            // cout<<q.top().first<<" ";
            temp->next = q.top().second;
            temp = temp->next;
            q.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}