// Find the missing and repeating number
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// Placing every element in its correct position
// Time Complexity: O(n) , Auxiliary Space: O(1)
#include <iostream>
#include <unordered_map>
using namespace std;

void printMissing_RepeatingElements(int arr[], int sz)
{
    int repeatig, missing;
    int i = 0;
    while (i < sz)
    {
        if (arr[i] == arr[arr[i] - 1])
            i++;
        else
            swap(arr[i], arr[arr[i] - 1]);
    }
    for (i = 0; i < sz; i++)
    {
        if (arr[i] != i + 1)
        {
            repeatig = arr[i];
            missing = i + 1;
            break;
        }
    }
    // Print answer
    cout << "Repeating: " << repeatig << endl
         << "Missing: " << missing << endl;
}

int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int sz = 6;
    printMissing_RepeatingElements(arr, sz);
    return 0;
}
