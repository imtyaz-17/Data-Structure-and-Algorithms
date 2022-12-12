// Find Union and Intersection of two sorted arrays
// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

// Use merge procedure
// Time Complexity:  O(l1 + l2) , Auxiliary Space: O(n).

#include <bits/stdc++.h>
using namespace std;

void UnionArray(int arr1[], int arr2[], int l1, int l2)
{
    int m = arr1[l1 - 1];
    int n = arr2[l2 - 1];
    int ans = 0;
    if (m > n)
        ans = m;
    else
        ans = n;
    int newtable[ans + 1];
    memset(newtable, 0, sizeof(newtable));

    cout << arr1[0] << " ";
    newtable[arr1[0]]++;

    for (int i = 1; i < l1; i++)
    {
        if (arr1[i] != arr1[i - 1])
        {
            cout << arr1[i] << " ";
            newtable[arr1[i]]++;
        }
    }
    for (int j = 0; j < l2; j++)
    {
        if (newtable[arr2[j]] == 0)
        {
            cout << arr2[j] << " ";
            newtable[arr2[j]]++;
        }
    }
}
int main()
{
    int arr1[] = {1, 2, 2, 2, 3};
    int arr2[] = {2, 3, 4, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    UnionArray(arr1, arr2, n, m);

    return 0;
}
