// Find common elements in three sorted arrays
// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

// by counting frequency / handle_duplicate_elements / use an array instead of a map
// Time Complexity:  O(n1 + n2)  , Auxiliary Space: O(maximum element in array)).

#include <bits/stdc++.h>
using namespace std;

void commonElements(vector<int> arr1, vector<int> arr2, vector<int> arr3, int n1, int n2, int n3)
{
    int Max = INT_MIN;

    int res1 = 1;
    for (int i = 1; i < n1; i++)
    {
        Max = max(arr1[i], Max);

        if (arr1[i] != arr1[res1 - 1])
        {
            arr1[res1] = arr1[i];
            res1++;
        }
    }

    int res2 = 1;
    for (int i = 1; i < n2; i++)
    {
        Max = max(arr2[i], Max);
        if (arr2[i] != arr2[res2 - 1])
        {
            arr2[res2] = arr2[i];
            res2++;
        }
    }

    int res3 = 1;
    for (int i = 1; i < n3; i++)
    {
        Max = max(arr3[i], Max);
        if (arr3[i] != arr3[res3 - 1])
        {
            arr3[res3] = arr3[i];
            res3++;
        }
    }

    vector<int> freq(Max + 1, 0);

    for (int i = 0; i < res1; i++)
    {
        freq[arr1[i]]++;
    }
    for (int i = 0; i < res2; i++)
    {
        freq[arr2[i]]++;
    }
    for (int i = 0; i < res3; i++)
    {
        freq[arr3[i]]++;
    }

    for (int i = 0; i <= Max; i++)
    {
        if (freq[i] == 3)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    commonElements(arr1, arr2, arr3, 6, 5, 8);
    return 0;
}