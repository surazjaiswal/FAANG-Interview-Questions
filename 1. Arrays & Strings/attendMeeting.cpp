#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> time;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start;
        cin >> end;
        time.push_back({start, end});
    }

    sort(time.begin(), time.end(), cmp);

    int prevEnd = 0;
    for (auto it : time)
    {
        if (prevEnd > it.first)
        {
            cout << "false" << endl;
            return 0;
        }
        prevEnd = it.second;
    }

    cout << "true" << endl;

    return 0;
}