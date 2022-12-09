// Zigzag (or diagonal) traversal of Matrix
// https://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/

// method 2
// Time Complexity:  O(row x col)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 4

bool isValid(int i, int j)
{
    if (i < 0 || i >= ROW || j >= COL || j < 0)
        return false;
    return true;
}

void diagonalOrder(int matrix[][COL])
{
    for (int k = 0; k < ROW; k++)
    {
        cout << matrix[k][0] << " ";
        int i = k - 1;
        int j = 1;

        while (isValid(i, j))
        {
            cout << matrix[i][j] << " ";
            i--;
            j++;
        }
        cout << endl;
    }
    for (int k = 1; k < COL; k++)
    {
        cout << matrix[ROW - 1][k] << " ";
        int i = ROW - 2;

        int j = k + 1;

        while (isValid(i, j))
        {
            cout << matrix[i][j] << " ";
            i--;

            j++;
        }
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