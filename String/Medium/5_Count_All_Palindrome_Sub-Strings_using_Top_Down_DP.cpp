// Count All Palindrome Sub-Strings in a String | Set 1
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/

// using  Top Down DP i.e memoized version of recursion.
// Time Complexity: O(n^2) , Auxiliary Space: O(n^2).

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
bool isPal(string s, int i, int j)
{
    if (i > j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] != s[j])
        return dp[i][j] = 0;
    
    return dp[i][j] = isPal(s,i+1,j-1);
}
int CountPalStr(string s)
{
    memset(dp, -1, sizeof(dp));
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPal(s, i, j))
                count++;
        }
    }

    return count;
}
int main()
{
    string s = "abbaeae";

    cout << CountPalStr(s);
    return 0;
}