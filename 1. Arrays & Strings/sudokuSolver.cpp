#include <bits/stdc++.h>
using namespace std;

bool canBePlaced(vector<vector<int>> &sudoku, int i, int j, int k, int n)
{
    // cheking in the row and col simultaneously
    for (int a = 0; a < n; a++)
    {
        if (sudoku[i][a] == k || sudoku[a][j] == k)
            return false;
    }

    // checking for current curr grid (3*3) n=9
    int sq = sqrt(n);       // grid size
    int sx = (i / sq) * sq; // ith(row) starting point of current grid
    int sy = (j / sq) * sq; // jth(col) starting point of current grid
    for (int x = sx; x < sx + sq; x++)
    {
        for (int y = sy; y < sy + sq; y++)
        {
            if (sudoku[x][y] == k)
                return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &sudoku, int i, int j, int n)
{
    // base case
    // if reached at the end that means suduko is solved
    if (i == n)
    {
        return true;
    }

    // if reached at the end of the row, move to next row
    if (j == n)
    {
        solveSudoku(sudoku, i + 1, 0, n);
    }
    // if current_cell value is non_empty or non_zero
    if (sudoku[i][j] != 0)
    {
        solveSudoku(sudoku, i, j + 1, n);
    }

    // at this point point we are at a empty cell
    // now we will fill this cell with 1 <= k <= 9
    // and check progressivly checking its validity and futher existance of solution

    for (int k = 1; k <= n; k++)
    {
        if (canBePlaced(sudoku, i, j, k, n)) // to check if k is acceptable for this cell or not
        {
            sudoku[i][j] = k;                                 // place current k value in the cell
            bool isSolved = solveSudoku(sudoku, i, j + 1, n); // assuming that by placing curr_k our sudoku is solved, check for next cell
            if (isSolved)
            {
                return true; // sudoku is solved
            }
        }
    }
    sudoku[i][j] = 0; // backtracking step if curr_k was not able to solve
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> sudoku(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    bool solved = solveSudoku(sudoku, 0, 0, n);
    cout << "completed" << endl;
    // print suduko
    for (auto it : sudoku)
    {
        for (int num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}