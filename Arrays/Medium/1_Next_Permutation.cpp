// Next Permutation
// https://www.geeksforgeeks.org/next-permutation/

// Next Permutation in linear time complexity
// Time Complexity: O(N), Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr)
{
    int sz = arr.size();
    int i, j;
    for (i = sz - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            break;
        }
    }

    if (i < 0)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        for (j = sz - 1; j > i; j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
        }
        swap(arr[i], arr[j]);

        reverse(arr.begin() + i + 1, arr.end());
    }

    for ( i = 0; i < sz; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 6, 5, 4};
    nextPermutation(arr);
    return 0;
}
