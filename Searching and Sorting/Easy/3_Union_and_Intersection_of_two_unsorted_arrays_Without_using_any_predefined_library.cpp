// Find Union and Intersection of two unsorted arrays
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

// Without using  any predefined library
// Time Complexity:  O()  , Auxiliary Space: O().

#include <bits/stdc++.h>
using namespace std;

void printUnion(int a[], int b[], int m, int n)
{
    int *result = new int[m + n];
    int index = 0;
    int left = 0, right = 0;

    while (left < m && right < n)
    {
        if (a[left] < b[right])
        {
            if (index != 0 && a[left] == result[index - 1])
            {
                left++;
            }
            else
            {
                result[index] = a[left];
                left++;
                index++;
            }
        }
        else
        {
            if (index != 0 && b[right] == result[index - 1])
            {
                right++;
            }
            else
            {
                result[index] = b[right];
                right++;
                index++;
            }
        }
    }
    while (left < m)
    {
        if (index != 0 && a[left] == result[index - 1])
        {
            left++;
        }
        else
        {
            result[index] = a[left];
            left++;
            index++;
        }
    }

    while (right < n)
    {
        if (index != 0 && b[right] == result[index - 1])
        {
            right++;
        }
        else
        {
            result[index] = b[right];
            right++;
            index++;
        }
    }

    cout << "Union of two arrays is " << endl;
    for (int k = 0; k < index; k++)
    {
        cout << result[k] << " ";
    }
    cout << endl;
}
void printIntersection(int a[], int b[], int m, int n)
{
    int i = 0, j = 0, k = 0;

    int *result = new int[m + n];

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            if (k != 0 && a[i] == result[k - 1])
            {
                i++;
                j++;
            }
            else
            {
                result[k] = a[i];
                i++;
                j++;
                k++;
            }
        }
    }

    cout << "Intersection of two arrays is " << endl;
    for (int l = 0; l < k; l++)
    {
        cout<<result[l]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr1[] = {1, 3, 2, 3, 3, 4, 5, 5, 6};
    int arr2[] = {3, 3, 5};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // sort
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    printUnion(arr1, arr2, m, n);
    printIntersection(arr1, arr2, m, n);
    return 0;
}