#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n),vt(n+1,0),ans;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if(vt[nums[i]])
            ans.push_back(nums[i]);
        vt[nums[i]]++;
    }
    for (int i : ans)
        cout << i << " ";

    return 0;
}