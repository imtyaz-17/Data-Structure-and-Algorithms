// Find Union and Intersection of two unsorted arrays
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

// Kind of hashing technique without using any predefined Java Collections
// Time Complexity:  O(m+n)  , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

void placeValue(int a[], int ans[], int i, int p, int v)
{
    p = p % v;

    if (ans[p] == 0)
    {
        ans[p] = a[i];
    }
    else
    {
        if (ans[p] == a[i])
        {
            cout << a[i] << " ";
        }
        else
        {
            p = p + 1;
            placeValue(a, ans, i, p, v);
        }
    }
}
int iterateArray(int a[], int v, int ans[], int i)
{
    if (a[i] != 0)
    {
        int p = a[i] % v;
        placeValue(a, ans, i, p, v);
    }
    else
    {
        return 1;
    }

    return 0;
}
void placeZeros(int v, int ans[], int zero)
{
    if (zero == 2)
    {
        cout << "0" << endl;
        int d[] = {0};
        placeValue(d, ans, 0, 0, v);
    }
    if (zero == 1)
    {
        int d[] = {0};
        placeValue(d, ans, 0, 0, v);
    }
}
void printUnion(int v, int ans[], int zero)
{
    int zero1 = 0;
    cout << "\nUnion : ";

    for (int i = 0; i < v; i++)
    {
        if ((zero == 0 && ans[i] == 0) || (ans[i] == 0 && zero1 > 0))
        {
            continue;
        }
        if (ans[i] == 0)
            zero1++;
        cout << ans[i] << " ";
    }
}
void findPosition(int a[], int b[], int n1, int n2)
{
    int v = n1 + n2;

    int ans[v];
    for (int i = 0; i < v; i++)
    {
        ans[i] = 0;
    }
    int zero1 = 0;
    int zero2 = 0;

    cout << "Intersection : ";
    for (int i = 0; i < n1; i++)
    {
        zero1 = iterateArray(a, v, ans, i);
    }
    for (int j = 0; j < n2; j++)
        zero2 = iterateArray(b, v, ans, j);

    int zero = zero1 + zero2;
    placeZeros(v, ans, zero);
    printUnion(v, ans, zero);
}

int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findPosition(arr1, arr2, n1, n2);

    return 0;
}