// Find the missing and repeating number
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// Use XOR
// Time Complexity: O(n) , Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

void printMissing_RepeatingElements(int arr[], int sz, int *x, int *y)
{
    int xor1;
    int set_bit_no;

    int i;
    *x = 0;
    *y = 0;

    xor1 = arr[0];
    for (i = 1; i < sz; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    for (i = 1; i <= sz; i++)
    {
        xor1 = xor1 ^ i;
    }

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    for (i = 0; i < sz; i++)
    {
        if (arr[i] & set_bit_no)
            *x = *x ^ arr[i];
        else
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= sz; i++)
    {
        if (i & set_bit_no)
        {
            *x = *x ^ i;
        }
        else
        {
            *y = *y ^ i;
        }
    }
}
int main()
{
    int arr[] = {1, 3, 4, 5, 5, 6, 2};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));
    printMissing_RepeatingElements(arr, sz, x, y);
    cout << " The missing element is " << *x
         << " and the repeating number is " << *y;
}
