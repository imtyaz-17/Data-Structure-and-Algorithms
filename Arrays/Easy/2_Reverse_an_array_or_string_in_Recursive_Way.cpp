// Write a program to reverse an array or string
//  https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

// reverse an array in Recursive Way:

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int sz = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, sz);

    reverseArray(arr, 0, sz - 1);

    cout << "Reversed array is" << endl;
    printArray(arr, sz);

    return 0;
}