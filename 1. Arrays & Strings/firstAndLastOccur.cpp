#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == x)
        {
            int a = mid, b = mid;
            while (a >= 0 && nums[a] == x)
                a--; // finding its first ouccurance
            while (b < nums.size() && nums[b] == x)
                b++; // finding last occurance
            cout << a << " " << b << endl;
            // return {a + 1, b - 1};
        }
        else if (nums[mid] > x)
            end = mid - 1;

        else
            start = mid + 1;
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}