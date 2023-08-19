#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
bool isAllowed(int row, int col, vector<vector<int>> &smallPart, int val)
{
    for (int i = 0; i < smallPart.size(); i++)
    {
        if (smallPart[row][i] == val)
        {
            return false;
        }
        if (smallPart[i][col] == val)
        {
            return false;
        }
        if (smallPart[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& smallPart)
{
    int n = smallPart[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (smallPart[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isAllowed(row, col, smallPart, val))
                    {
                        smallPart[row][col] = val;
                        if (solveSudoku(smallPart))  // Recursive call
                        {
                            return true;
                        }
                        smallPart[row][col] = 0;  // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSudoku(const vector<vector<int>>& sudoku)
{
    for (const auto& row : sudoku)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
