// Print a given matrix in zigzag form
// https://www.geeksforgeeks.org/print-given-matrix-zigzag-form/

//
// Time Complexity:  O(row*column)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

void printZigZag(int row, int col, int a[][MAX])
{
    int evenRow = 0;
    int oddRow = 1;

    while (evenRow < row)
    {
        for (int i = 0; i < col; i++)
        {
            cout << a[evenRow][i] << " ";
        }
        evenRow = evenRow + 2;

        if (oddRow < row)
        {
            for (int i = col - 1; i >= 0; i--)
            {
                cout << a[oddRow][i] << " ";
            }
        }
        oddRow = oddRow + 2;
    }
}

int main()
{
    int r = 3, c = 5;
    int mat[][MAX] = {{1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15}};

    printZigZag(r, c, mat);
    return 0;
}