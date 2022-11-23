// Longest Common Prefix using Character by Character Matching
// https://www.geeksforgeeks.org/longest-common-prefix-using-character-by-character-matching/

// using Character by Character Matching
// Time Complexity: O(N M) , Auxiliary Space: O(M).

#include <bits/stdc++.h>
using namespace std;

int findMinLength(string arr[], int n)
{
    int minn = arr[0].length();

    for (int i = 1; i < n; i++)
    {
        if(arr[i].length() <minn)
        minn = arr[i].length();
    }
    return minn;
}
string longestCommonPrefix(string arr[], int n)
{
    int minlen = findMinLength(arr,n);
    string result ;
    char current ;

    for (int  i = 0; i < minlen; i++)
    { 
        current = arr[0][i];
        for (int  j = 1; j < n; j++)
        {
            if(arr[j][i] != current)
            return result;
        }

        result+=current;
        
    }

    return result;
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);

    string ans = longestCommonPrefix(arr, n);

    if (ans.length())
        cout << "The longest common prefix is "
             << ans;
    else
        cout << "There is no common prefix";
    return (0);
}