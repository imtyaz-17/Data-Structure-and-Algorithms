// Search an element in an array where difference between adjacent elements is 1
// https://www.geeksforgeeks.org/search-an-element-in-an-array-where-difference-between-adjacent-elements-is-1/

// difference between all adjacent elements is 1
// Time Complexity:  O(n)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int x)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;
        else
        {
            i =i+ abs(arr[i]-x);
        }
    }

    //cout << "number is not present!";
    return -1;
}
int main()
{
    int arr[] = {8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;
    cout << "Element " << x << " is present at index "
         << search(arr, n, x);
    return 0;
}