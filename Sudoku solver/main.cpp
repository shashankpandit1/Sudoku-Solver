#include <iostream>
#include <vector>
#include <fstream>
#include"solver.cpp"
using namespace std;


int main()
{
    ifstream inputFile("sudoku_input.txt");
    if (!inputFile.is_open())
    {
        cout << "Error." << endl;
    }

    int numTestCases;
    inputFile >> numTestCases;  // Reading the number of test cases

    for (int test = 1; test <= numTestCases; test++)
    {
        vector<vector<int>> sudoku(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                inputFile >> sudoku[i][j];
            }
        }

        cout << "\nTest Case " << test << ":" << endl;
        cout << "Input Sudoku:" << endl;
        printSudoku(sudoku);

        if (solveSudoku(sudoku))
        {
            cout << "\nSolved Sudoku:" << endl;
            printSudoku(sudoku);
        }
        else
        {
            cout << "\nNo solution exists." << endl;
        }
    }

    inputFile.close();
    return 0;
}
