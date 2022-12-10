// Print a given matrix in antispiral form
// https://www.geeksforgeeks.org/print-matrix-antispiral-form/

// using stack
// Time Complexity:  O(row*column)  , Auxiliary Space: O(row*column).

#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 5

void antiSpiralTraversal(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
    stack<int> stk;

    while (k <= m && l <= n)
    {
        for (i = l; i <= n; i++)
            stk.push(a[k][i]);
        k++;

        for (i = k; i <= m; i++)
            stk.push(a[i][n]);
        n--;

        if (k <= m)
        {
            for (i = n; i >= l; i--)
                stk.push(a[m][i]);
            m--;
        }
        if (l <= n)
        {
            for (i = m; i >= k; i--)
                stk.push(a[i][l]);
            l++;
        }
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}
int main()
{
    int mat[R][C] =
        {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20}};

    antiSpiralTraversal(R - 1, C - 1, mat);
    return 0;
}