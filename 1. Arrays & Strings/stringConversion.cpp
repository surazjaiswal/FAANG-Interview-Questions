#include <bits/stdc++.h>
using namespace std;

bool checkString(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (s1 == s2)
        return false;

    if (abs(n1 - n2) > 1)
        return false;

    int cnt = 1;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (s1[i] != s2[j])
        {
            if (cnt)
                cnt--;
            else
                return false;
        }
        i++, j++;
    }

    return true;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    string str1, str2;
    cin >> str1 >> str2;

    if (checkString(str1, str2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}