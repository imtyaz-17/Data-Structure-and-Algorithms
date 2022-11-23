// Longest Common Prefix using Word by Word Matching
// https://www.geeksforgeeks.org/longest-common-prefix-using-word-by-word-matching/

// using Word by Word Matching
// Time Complexity: O(N M) , Auxiliary Space: O(M).

#include <bits/stdc++.h>
using namespace std;

string commonPrefix(string &str1, string &str2)
{
    string result = "";
    int len = min(str1.length(), str2.length());

    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
            break;

        result += str1[i];
    }

    return (result);
}
string longestCommonPrefix(string arr[], int n)
{
    string prefix = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix = commonPrefix(prefix, arr[i]);

        return (prefix);
    }
}
int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);

    string ans = longestCommonPrefix(arr, n);

    if (ans.length())
        printf("The longest common  prefix is : %s",
               ans.c_str());
    else
        printf("There is no common prefix");

    return (0);
}