//  Maximum Subarray
//  https://leetcode.com/problems/maximum-subarray/

// Maximum Subarray using brute force approach:
#include <bits/stdc++.h>
using namespace std;

void maxSubArray(int arr[], int n)
{
    int ans = -111111;
    // Pick starting point
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // Pick ending point
        for (int j = i; j < n; j++)
        {

            sum += arr[j];
            ans = max(ans, sum);
        }
        
    }

    cout << ans << endl;
}

// Driver program
int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "All Non-empty Subarrays\n";
    maxSubArray(arr, n);
    return 0;
}
