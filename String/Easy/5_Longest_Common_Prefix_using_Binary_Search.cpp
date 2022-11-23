// Longest Common Prefix using Binary Search
// https://www.geeksforgeeks.org/longest-common-prefix-using-binary-search/

// using Binary Search
// Time Complexity: O(NM log M) , Auxiliary Space: O(N).

#include <bits/stdc++.h>
using namespace std;
int findMinLength(string arr[], int n)
{
    int minl = INT_MAX;

    for (int i = 0; i <= n - 1; i++)
        if (arr[i].length() < minl)
            minl = arr[i].length();
    return (minl);
}

bool allContainsPrefix(string arr[], int n, string str, int start, int end)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = start; j <= end; j++)
        {
            if (arr[i][j] != str[j])
                return false;
        }
    }

    return true;
}
string longestCommonPrefix(string arr[], int n)
{
    int index = findMinLength(arr, n);

    string prefix;

    int low = 0, high = index;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if(allContainsPrefix(arr, n, arr[0], low, mid)){
            prefix += arr[0].substr(low, mid-low+1);

            low =mid+1;
        }else{
            high = mid-1;
        }

    }

    return prefix;
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);

    string ans = longestCommonPrefix(arr, n);

    if (ans.length())
        cout << "The longest common prefix is : "
             << ans;
    else
        cout << "There is no common prefix";
    return (0);
}