// Find Union and Intersection of two sorted arrays
// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

//  handle duplicate elements in arrays
// Time Complexity:  O(m+n) , Auxiliary Space: O(min(m, n)).

#include <bits/stdc++.h>
using namespace std;

void print_intersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    set<int> s;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            s.insert(arr2[j]);
            i++;
            j++;
        }
    }

    for (auto it : s)
    {
        cout << it << " ";
    }
}
int main()
{
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 4, 6, 7, 8};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    print_intersection(arr1, arr2, m, n);

    return 0;
}