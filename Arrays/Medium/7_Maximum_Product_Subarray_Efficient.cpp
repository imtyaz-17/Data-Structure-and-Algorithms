// Maximum Product Subarray
// https://www.geeksforgeeks.org/maximum-product-subarray/

// Efficient Solution:
// Time Complexity: O(N) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

long long maxSubarrayProduct(int arr[], int n)
{
    long long  max_ending = arr[0];
    long long  min_ending = arr[0];

    long long  maxSub = arr[0];

    for (int i = 1; i < n; i++)
    {
        long long  temp = max<long long int>({arr[i], arr[i] * max_ending, arr[i] * min_ending});
        min_ending = min<long long int>({arr[i], arr[i] * max_ending, arr[i] * min_ending});
        max_ending = temp;

        maxSub = max(maxSub, max_ending);
    }
    return maxSub;

}
int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}