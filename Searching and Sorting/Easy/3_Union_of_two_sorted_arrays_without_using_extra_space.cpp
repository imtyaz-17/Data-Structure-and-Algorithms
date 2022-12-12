// Find Union and Intersection of two sorted arrays
// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

// without using any extra space
// Time Complexity:  O(m+n) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
void next_distinct(const vector<int> &arr, int &x)
{
    do
    {
        x++;
    } while (x < arr.size() && arr[x - 1] == arr[x]);
}
void printUnion(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            next_distinct(arr1, i);
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j] << " ";
            next_distinct(arr2, j);
        }
        else
        {
            cout << arr1[i] << " ";
            next_distinct(arr1, i);
            next_distinct(arr2, j);
        }
    }

    while (i < arr1.size())
    {
        cout << arr1[i] << " ";
        next_distinct(arr1, i);
    }
    while (j < arr2.size())
    {
        cout << arr2[j] << " ";
        next_distinct(arr2, j);
    }
}
int main()
{
    vector<int> arr1 = {1, 2, 2, 2, 3};    // Duplicates Present
    vector<int> arr2 = {2, 3, 3, 4, 5, 5}; // Duplicates Present

    printUnion(arr1, arr2);

    return 0;
}
