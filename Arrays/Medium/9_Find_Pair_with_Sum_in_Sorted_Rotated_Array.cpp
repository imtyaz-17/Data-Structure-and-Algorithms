// Find if there is a pair with a given sum in the rotated sorted Array
// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

// use a similar meet-in-middle algorithm :
// Time Complexity: O(N) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool pairInSortedRotated(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
            break;
    }

    int left = (i + 1) % n;
    int right = i;

    while (left != right)
    {
        if(arr[left] + arr[right] == x)
        return true;

        if(arr[left] +arr[right] < x)
        left = (left +1)%n;

        else
        right = (n+right -1) % n;
    }

    return false;
}
int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int X = 16;
    int N = sizeof(arr) / sizeof(arr[0]);

  if (pairInSortedRotated(arr, N, X))
        cout << "Yes";
    else
        cout << "NO";

    return 0;
}
