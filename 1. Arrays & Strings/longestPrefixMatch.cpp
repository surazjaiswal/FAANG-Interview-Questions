#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    if (n == 0)
    {
        cout << "" << endl;
        return 0;
    }

    string ans = words[0];
    for (int i = 1; i < n; i++)
    {
        string temp = ""; // string matched till now
        for (int j = 0; j < min(ans.length(), words[i].length()); j++)
        {
            if (ans[j] == words[i][j])
            {
                temp += ans[j];
            }
            else
            {
                break;
            }
        }
        ans = temp;
    }

    cout << ans << endl;

    return 0;
}