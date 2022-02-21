#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> start(n), end(n);
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int ans = 0;
    int hall_in_use = 0;
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (start[i] < end[j])
        {
            hall_in_use++;
            i++;
        }
        else
        {
            hall_in_use--;
            j++;
        }
        ans = max(ans, hall_in_use);
    }

    cout << ans << endl;
    return 0;
}