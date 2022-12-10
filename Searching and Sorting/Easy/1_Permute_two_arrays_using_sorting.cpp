// Permute two arrays such that sum of every pair is greater or equal to K
// https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

// using sorting
// Time Complexity:  O(nlogn)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int b[], int n, int k)
{
    sort(a, a + n);

    sort(b, b + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (a[i] + b[i] < k)
            return false;
    }

    return true;
}
int main()
{
    int a[] = {2, 1, 3};
    int b[] = {7, 8, 9};
    int k = 10;
    int n = sizeof(a) / sizeof(a[0]);

    isPossible(a, b, n, k) ? cout << "Yes" : cout << "No";
    return 0;
}