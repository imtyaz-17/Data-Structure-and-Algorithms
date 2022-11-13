//  Maximum Subarray
//  https://leetcode.com/problems/maximum-subarray/

// Maximum Subarray using Kaden's Algorithm:
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[], int sz)
{
    if (sz == 0)
        return 0;
    int max = INT_MIN;
    int csum = 0;
    for (int i = 0; i < sz; i++)
    {
        if (csum + arr[i] > arr[i])
        {
            csum += arr[i];
        }
        else
        {
            csum = arr[i];
        }

        if (csum > max)
            max = csum;
    }
    return max;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sz = sizeof(arr) / sizeof(arr[0]);
    cout << "All Non-empty Subarrays\n";
    int ans = maxSubArray(arr, sz);
    cout << ans << endl;
    return 0;
}