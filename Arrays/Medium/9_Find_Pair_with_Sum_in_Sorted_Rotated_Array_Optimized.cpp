// Find if there is a pair with a given sum in the rotated sorted Array
// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

// use a similar meet-in-middle algorithm && pivot optimized to O(Logn) using the Binary Search approach :
// Time Complexity: O(N) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool pairInSortedRotated(int arr[], int n, int x)
{

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[left] + arr[mid] == x)
            return true;
        if (arr[mid] + arr[right] == x)
            return true;

        if (arr[left] + arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}
int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int X = 160;
    int N = sizeof(arr) / sizeof(arr[0]);

    if (pairInSortedRotated(arr, N, X))
        cout << "Yes";
    else
        cout << "NO";

    return 0;
}
