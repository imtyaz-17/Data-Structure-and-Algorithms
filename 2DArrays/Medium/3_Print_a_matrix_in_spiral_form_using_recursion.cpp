// Print a given matrix in spiral form
// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

// using recursion:
// Time Complexity:  O(M*N)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

void spiralPrint(int arr[R][C], int k, int l, int m, int n)
{
    if (k >= m || l >= n)
        return;
    for (int i = l; i < n; i++)
    {
        cout << arr[k][i] << " ";
    }
    for (int i = k + 1; i < m; i++)
    {
        cout << arr[i][n - 1] << " ";
    }
    if ((m - 1) != k)
    {
        for (int i = n - 2; i >= l; i--)
        {
            cout << arr[m - 1][i] << " ";
        }
    }
    if ((n - 1) != l)
    {
        for (int i = m - 2; i > k; i--)
        {
            cout << arr[i][l] << " ";
        }
    }
    spiralPrint(arr, k + 1, l + 1, m - 1, n - 1);
}
int main()
{
    int a[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};

    spiralPrint(a, 0, 0, R, C);
    return 0;
}