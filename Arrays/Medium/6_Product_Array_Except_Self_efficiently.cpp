// Product of Array except itself
// https://www.geeksforgeeks.org/a-product-array-puzzle/

// Efficient solution:
// Time Complexity: O(n) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

long *productExceptSelf(int a[], int n)
{
    long prod = 1;
    long flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            flag++;
        else
            prod *= a[i];
    }

    long *arr = new long[n];
    for (int i = 0; i < n; i++)
    {
        if (flag > 1)
        {
            arr[i] = 0;
        }
        else if (flag == 0)
        {
            arr[i] = prod / a[i];
        }
        else if(flag==1 & a[i]!=0){
                arr[i]=0;
        }else{
            arr[i] = prod;
        }
    }
    return arr;
}
int main()
{
    int arr[] = {10, 3, 5, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    long *ans;
    ans = productExceptSelf(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}