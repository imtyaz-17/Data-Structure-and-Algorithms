// Counting Sort
// https://www.geeksforgeeks.org/counting-sort/

//
// Time Complexity:  O(N + K)  , Auxiliary Space: O(N + K).

#include <bits/stdc++.h>
using namespace std;

void countSort(char arr[])
{
    char output[strlen(arr)];

    int count[255], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; i++)
        count[arr[i]]++;
    for (i = 1; i <= 255; i++)
        count[i] += count[i - 1];
    for (i = 0; arr[i]; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
int main()
{
    char arr[] = "geeksforgeeks";

    countSort(arr);

    cout << "Sorted character array is " << arr;
    return 0;
}