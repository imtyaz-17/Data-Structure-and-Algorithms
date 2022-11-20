// Find all triplets with zero sum
// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

// using  Sorting:
// Time Complexity: O(n2) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

void findTriplets(int arr[], int n)
{
    bool found = false;
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        int left = i + 1;
        int right = n - 1;
        int x = arr[i];

        while (left < right)
        {
            if (x + arr[left] + arr[right] == 0)
            {
                printf("%d %d %d\n", x, arr[left], arr[right]);
                left++;
                right--;
                found = true;
            }
            else if (x + arr[left] + arr[right] < 0)
            {
                left++;
            }
            else{
                right--;
            }
        }
    }

    if (found == false)
        cout << " No Triplet Found" << endl;
}

int main()
{
    int arr[] = {-1,0,1,2,-1,-4};
    int n = sizeof(arr) / sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}