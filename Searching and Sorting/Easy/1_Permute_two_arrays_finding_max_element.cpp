// Permute two arrays such that sum of every pair is greater or equal to K
// https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

// finding max element
// Time Complexity:  O(n)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int b[], int n, int k)
{
    int max_a = *max_element(a, a+n);
    int max_b = *max_element(b, b+n);

    int ans = max_a+max_b;

    return ans>=k;

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