// Find the Minimum element in a Sorted and Rotated Array
// https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

// using Linear Serach:
// Time Complexity: O(N) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{
    int min_element = arr[0];

    for (int  i = 0; i < n; i++)
    {
        if(arr[i]<min_element)
        min_element = arr[i];
    }
    return min_element;
}
int main()
{
    int arr[] = {5, 6, 1, 2, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << findMin(arr, N) << endl;
    return 0;
}