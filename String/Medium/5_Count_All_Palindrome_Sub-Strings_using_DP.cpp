// Count All Palindrome Sub-Strings in a String | Set 1
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/

// using dynamic programming
// Time Complexity: O(n^2) , Auxiliary Space: O(n^2).

#include <bits/stdc++.h>
using namespace std;
int CountPalStr(char str[], int n)
{
    int ans = 0;

    bool P[n][n];
    memset(P, false, sizeof(P));

    for (int i = 0; i < n; i++)
    {
        P[i][i] = true;
    }

    for (int ln = 2; ln <= n; ln++)
    {
        for (int i = 0; i < n - ln; i++)
        {
            int j = ln + i - 1;

            if (i == j - 1)
            {
                P[i][j] = (str[i] == str[j]);
            }
            else
            {
                P[i][j] = (str[j] && P[i + 1][j - 1]);
            }

            if (P[i][j])
            {
                ans++;
            }
        }
    }

    return ans;
}
int main()
{
    char str[] = "abaab";
    int n = strlen(str);
    cout << CountPalStr(str, n) << endl;
    return 0;
}