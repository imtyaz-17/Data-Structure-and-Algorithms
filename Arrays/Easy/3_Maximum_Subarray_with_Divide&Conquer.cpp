//  Maximum Subarray
//  https://leetcode.com/problems/maximum-subarray/

// Maximum Subarray using divide and conquer approach:
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[], int left, int right)
{
    if (left == right)
        return arr[left];

    int mid = left + (right - left) / 2;
    int leftMax = maxSubArray(arr, left, mid);
    int rightMax = maxSubArray(arr, mid + 1, right);

    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;

    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    int midSum = leftSum + rightSum;

    int max = leftMax > rightMax ? (leftMax > midSum ? leftMax : midSum) : (rightMax > midSum ? rightMax : midSum);
    return max;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "All Non-empty Subarrays\n";
    int ans = maxSubArray(arr, 0, n - 1);
    cout << ans << endl;
    return 0;
}