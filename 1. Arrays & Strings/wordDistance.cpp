#include <bits/stdc++.h>
using namespace std;

// brute force will take around O(n^2) time
// this to optimize it we use two pointers and everytime we update the
// index of word_1 and word_2 when they encounter
// and when they both have been encountered then progressivley calculate
// the absolute distance between them
// this two pointer approach will work in O(n) time ans constant space

int main()
{

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    string word_1, word_2;
    cin >> word_1 >> word_2;

    int w1 = -1, w2 = -1;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (words[i] == word_1)
        {
            w1 = i;
        }
        if (words[i] == word_2)
        {
            w2 = i;
        }
        if (w1 != -1 && w2 != -1)
        {
            ans = min(ans, abs(w2 - w1));
        }
    }
    cout << ans << endl;
    return 0;
}