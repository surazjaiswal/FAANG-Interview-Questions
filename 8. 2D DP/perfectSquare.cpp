#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {

        // if given number is itself perfect number
        if (isPerfectSq(n))
            return 1;

        // chking for sum of two squares
        for (int i = 1; i * i < n; i++)
        {
            // choosing i*i as first square
            // check for the remaining part, is it perfect sqaure or not
            if (isPerfectSq(n - i * i))
                return 2;
        }

        // check if it satisfies legendres function
        // Legendre’s three-square theorem states that a natural number can be represented as the
        // sum of three squares of integers if and only if
        // n is not of the form : n = 4a (8b+7), for non-negative integers a and b.
        if (legendreFxn(n))
            return 3;

        // Lagrange’s four-square theorem, also known as Bachet’s conjecture,
        // states that every natural number can be represented as the sum of four integer squares,
        // where each integer is non-negative.

        return 4;
    }

    bool isPerfectSq(int num)
    {
        int val = sqrt(num);
        if (val * val == num)
            return true;
        return false;
    }

    bool legendreFxn(int num)
    {
        // 4^a * (8b + 7)
        while (num % 4 == 0)
        {
            num /= 4;
        }
        if (num % 8 != 7) // not legendre
            return true;
        else
            return false;
    }
};

int main()
{

    int n;
    cin >> n;

    Solution s;
    cout << s.numSquares(n) << endl;

    return 0;
}