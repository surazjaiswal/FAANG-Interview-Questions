#include <iostream>
#include <vector>

using namespace std;

int getUniqueStrLen(vector<string> &arr, string str, int i)
{
    // base case
    if (i == arr.size())
    {
        // now we have to check all the char in atr are unique or not
        vector<int> vt(26, 0);
        for (int k = 0; k < str.length(); k++)
        {
            if (vt[str[k] - 'a']) // this means that char already exists
                return 0;
            vt[str[k] - 'a']++;
        }
        return str.length();
    }

    // include
    int inc = 0;
    if (str.length() + arr[i].length() <= 26)
    {
        inc = getUniqueStrLen(arr, str + arr[i], i + 1);
    }

    // exlcude
    int exc = getUniqueStrLen(arr, str, i + 1);

    return max(inc, exc);
}

int main()
{

    int n;
    cin >> n;

    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    cout << getUniqueStrLen(arr, "", 0) << endl;

    return 0;
}