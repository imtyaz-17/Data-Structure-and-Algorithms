// Find common elements in three sorted arrays
// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

// using hash set
// Time Complexity:  O(n1 + n2 + n3)  , Auxiliary Space: O(n1 + n2 + n3).

#include <bits/stdc++.h>
using namespace std;

void findCommon(int a[], int b[], int c[], int n1, int n2, int n3)
{
    unordered_set<int> set1, set2, set3;

    for (int i = 0; i < n1; i++)
    {
        set1.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        set2.insert(b[i]);
    }

    // checking if elements of 3rd array are present in first 2 sets
    for (int i = 0; i < n3; i++)
    {
        if (set1.find(c[i]) != set1.end() && set2.find(c[i]) != set1.end())
        {
            if (set3.find(c[i]) == set3.end())
            {
                cout<<c[i]<<" ";
            }
            set3.insert(c[i]);
        }
    }
}

int main()
{
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    cout << "Common Elements are " << endl;
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}