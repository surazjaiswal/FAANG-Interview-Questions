#include <bits/stdc++.h>
using namespace std;

class Soultion
{
public:
    void resolveArrows(vector<int> &arr)
    {
        stack<int> stk;
        for (int i : arr)
        {
            if (stk.size() && (stk.top() > 0 && i < 0))
            {
                bool flag = true;
                while (stk.size() && (stk.top() > 0 && i < 0))
                {
                    // arrows will collide
                    if (abs(stk.top()) == abs(i))
                    {
                        stk.pop();
                        flag = false;
                    }
                    else if (abs(stk.top()) > abs(i))
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        stk.pop();
                        flag = true;
                    }
                }
                if (flag)
                    stk.push(i);
            }
            else
            {
                stk.push(i);
            }
        }

        vector<int> ans;
        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        for (int i : ans)
        {
            cout << i << " ";
        }
    }
};

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Soultion s;
    s.resolveArrows(arr);

    return 0;
}