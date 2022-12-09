// Zigzag (or diagonal) traversal of Matrix
// https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/

// method 3
// Time Complexity:  O(row x col)  , Auxiliary Space: O(row + col).

#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 4

void diagonalOrder(int matrix[][COL])
{
    vector<vector<int>> ans(ROW + COL - 1);

    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            ans[i+j].push_back(matrix[j][i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
 
        cout << endl;
    }
}
void printMatrix(int matrix[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            cout << setw(5) << matrix[i][j];

        cout << "\n";
    }
}
int main()
{
    int M[ROW][COL] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
    };
    cout << "Given matrix is " << endl;
    printMatrix(M);

    cout << "\nDiagonal printing of matrix is " << endl;
    diagonalOrder(M);
    return 0;
}