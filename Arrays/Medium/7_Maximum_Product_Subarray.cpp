// Maximum Product Subarray
// https://www.geeksforgeeks.org/maximum-product-subarray/

// Naive Solution
// Time Complexity: O(N2) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int arr[], int n)
{
    int result = arr[0];

    for(int i =0;i<n;i++){
        int prodct = arr[i];

        for(int j=i+1;j<n;j++){
            result = max(result, prodct);
            prodct *= arr[j];
        }
        result = max(result, prodct);
    }
    return result;
}
int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}