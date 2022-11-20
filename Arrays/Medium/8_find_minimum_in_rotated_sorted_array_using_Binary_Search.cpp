// Find the Minimum element in a Sorted and Rotated Array
// https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

// using Binary Search:
// Time Complexity: O(logN) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
    if (high < low)
        return arr[0];
    if (high == low)
        return arr[low];
    int mid = low + (high - low) / 2;

    if (mid < high && arr[mid + 1] < arr[mid])
        return arr[mid + 1];
    if (mid > low && arr[mid] < arr[mid - 1])
        return arr[mid];
    if (arr[high] > arr[mid])
        return findMin(arr, low, mid - 1);
    return findMin(arr, mid + 1, high);
}
int main()
{
    int arr[] = {5, 6, 1, 2, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "The minimum element is "
         << findMin(arr, 0, N - 1) << endl;
    return 0;
}