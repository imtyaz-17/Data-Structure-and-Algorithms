// Print a given matrix in spiral form
// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

// using DFS:
// Time Complexity:  O(M*N)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

bool isInBounds(int i, int j)
{
    if (i < 0 || i >= R || j < 0 || j >= C)
        return false;
    return true;
}
bool isBlocked(int matrix[R][C], int i, int j)
{
    if (!isInBounds(i, j))
        return true;

    if (matrix[i][j] == -1)
        return true;

    return false;
}

void spirallyDFSTravserse(int matrix[R][C], int i, int j, int dir, vector<int> &res)
{
    if (isBlocked(matrix, i, j))
        return;

    bool allblocked = true;
    for (int k = -1; k <= 1; k += 2)
    {
        allblocked = allblocked && isBlocked(matrix, i + k, j) && isBlocked(matrix, i, j + k);
    }
    res.push_back(matrix[i][j]);
    matrix[i][j] = -1;

    if (allblocked)
        return;
    int nxt_i = i;
    int nxt_j = j;
    int nxt_dir = dir;

    if (dir == 0) // right
    {
        if (!isBlocked(matrix, i, j + 1))
        {
            nxt_j++;
        }
        else
        {
            nxt_dir = 1;
            nxt_i++;
        }
    }
    else if (dir == 1) // down
    {
        if (!isBlocked(matrix, i + 1, j))
        {
            nxt_i++;
        }
        else
        {
            nxt_dir = 2;
            nxt_j--;
        }
    }
    else if (dir == 2) // left
    {
        if (!isBlocked(matrix, i, j - 1))
        {
            nxt_j--;
        }
        else
        {
            nxt_dir = 3;
            nxt_i--;
        }
    }
    else if (dir == 3) // up
    {
        if (!isBlocked(matrix, i - 1, j))
        {
            nxt_i--;
        }
        else
        {
            nxt_dir = 0;
            nxt_j++;
        }
    }

    spirallyDFSTravserse(matrix, nxt_i, nxt_j, nxt_dir, res);
}

vector<int> spirallyTraverse(int matrix[R][C])
{
    vector<int> res;
    spirallyDFSTravserse(matrix, 0, 0, 0, res);
    return res;
}
int main()
{
    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};

    vector<int> res = spirallyTraverse(a);
    int size = res.size();
    for (int i = 0; i < size; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}