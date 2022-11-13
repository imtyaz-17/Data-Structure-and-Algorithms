// Search an element in a sorted and rotated Array
// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

// Search in a Rotated Array using Binary Search
//  Time Complexity: O(log N)  Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

 
    int search(int A[], int l, int h, int key)
    {
        if (l > h)
            return -1;

        int mid = l + (h - l) / 2;

        if (A[mid] == key)
            return mid;

        if (A[l] <= A[mid])
        {
            if (key >= A[l] && key <= A[mid])
                return search(A, l, mid - 1, key);

            return search(A, mid + 1, h, key);
        }

        if (key > A[mid] && key <= A[h])
        {
            return search(A, mid + 1, h, key);
        }
        return search(A, l, mid - 1, key);
    }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        cout <<search(A, 0, n - 1, key) << endl;
    }
    return 0;
}