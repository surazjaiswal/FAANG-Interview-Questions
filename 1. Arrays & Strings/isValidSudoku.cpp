#include <bits/stdc++.h>
using namespace std;

bool canBePlaced(int a, int b, vector<vector<char>> &board)
{
    char num = board[a][b];
    // checking for rows and cols
    for (int x = 0; x < 9; x++)
    {
        if (board[a][x] == num && x != b)
            return false;
        if (board[x][b] == num && x != a)
            return false;
    }

    // chking in the sub-box
    int rn = sqrt(9);
    int sx = (a / rn) * rn;
    int sy = (b / rn) * rn;

    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (board[x][y] == num && x != a && y != b)
                return false;
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (!canBePlaced(i, j, board))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> matrix(9, vector<char>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> matrix[i][j];
        }
    }
    if (isValidSudoku(matrix))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}