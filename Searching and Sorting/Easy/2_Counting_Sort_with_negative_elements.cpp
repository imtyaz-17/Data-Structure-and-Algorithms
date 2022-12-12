// Counting Sort
// https://www.geeksforgeeks.org/counting-sort/

// with negative elements
// Time Complexity:  O(N)  , Auxiliary Space: O(N).

#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr)
{
    int maxx = *max_element(arr.begin(), arr.end());
    int minn = *min_element(arr.begin(), arr.end());
    int range = maxx - minn + 1;

    vector<int> count(range), output(arr.size());

    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - minn]++;
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    for (int i = arr.size()-1; i >= 0; i--)
    {
        output[count[arr[i] - minn] - 1] = arr[i];
        count[arr[i] - minn]--;
    }
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
    
    countSort(arr);
    printArray(arr);
    return 0;
}