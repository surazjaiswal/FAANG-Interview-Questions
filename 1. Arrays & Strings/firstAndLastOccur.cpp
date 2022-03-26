#include <iostream>
#include <vector>

using namespace std;

int main()
{

    long long n, x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
        cin >> nums[i];

    long long start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (nums[mid] == x)
        {
            long long a = mid, b = mid;
            while (a >= 0 && nums[a] == x)
            {
                a--; // finding its first ouccurance
            }
            while (b < nums.size() && nums[b] == x)
            {
                b++; // finding last occurance}
            }
            cout << a+1 << " " << b-1 << endl;
            // return {a + 1, b - 1};
            return 0;
        }
        else if (nums[mid] > x)
            end = mid - 1;

        else
            start = mid + 1;
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}