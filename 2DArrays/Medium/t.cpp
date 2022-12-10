// A Boolean Matrix Question
// https://www.geeksforgeeks.org/a-boolean-matrix-question/

// method 2 space-optimiz
// Time Complexity:  O(row x col)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>

using namespace std;
#define R 3
#define C 3

void modifyMatrix(bool mat[R][C])
{
    bool rowFlag;
    bool colFlag;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 && mat[i][j] == 1)
                rowFlag = true;
            if (j == 0 && mat[i][j] == 1)
                colFlag = true;

            if (mat[i][j] == 1)
            {
                mat[0][j] = 1;
                mat[i][0] = 1;
            }
        }
    }

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (mat[0][j] == 1 || mat[i][0] == 1)
            {
                mat[i][j] = 1;
            }
        }
    }

    if (rowFlag == true)
    {
        for (int i = 0; i < C; i++)

            mat[0][i] = 1;
    }
    if (colFlag == true)
    {
        for (int i = 0; i < R; i++)
            mat[i][0] = 1;
    }
}
void printMatrix(bool mat[R][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    bool mat[R][C] = {{0, 0, 0},
                      {0, 0, 0},
                      {0, 1, 0}};

    cout << "Input Matrix \n";
    printMatrix(mat);
    modifyMatrix(mat);
    printf("Matrix after modification \n");
    printMatrix(mat);
    return 0;
}