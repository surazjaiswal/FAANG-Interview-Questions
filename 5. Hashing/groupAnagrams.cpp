// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string str : strs)
        {
            string rev = str;
            sort(rev.begin(), rev.end());
            mp[rev].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it : mp)
        {
            vector<string> vt;
            for (auto s : it.second)
            {
                vt.push_back(s);
                cout << s << " ";
            }
            ans.push_back(vt);
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    Solution s;
    s.groupAnagrams(strs);

    return 0;
}