// Longest Palindromic Substring using Dynamic Programming
// https://www.geeksforgeeks.org/longest-palindromic-substring-using-dynamic-programming/

//  Dynamic Programming.
// Time Complexity: O(n^2) , Auxiliary Space: O(n^2).

#include <bits/stdc++.h>
using namespace std;

0void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
int longestPalSubstr(string str)
{
    int n = str.size();

    bool table[n][n];

    memset(table, false, sizeof(table));
    // All substrings of length 1 are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; i++)
    {
        table[i][i] = true;
    }

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            if (maxLength < 2) // Incase of conflict, return the substring which occurs first
            {
                start = i;
                maxLength = 2;
            }
        }
    }

    // Check for lengths greater than 2.
    // k is length of substring

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;

            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}
int main()
{
    string str = "aaaabbaa";
    int l = longestPalSubstr(str);
    cout << "\nLength is: " << l << endl;
    return 0;
}