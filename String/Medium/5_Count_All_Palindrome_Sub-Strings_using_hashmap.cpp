// Count All Palindrome Sub-Strings in a String | Set 2
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string-set-2/

// using hashmap
// Time Complexity: O(n^2) , Auxiliary Space: O(n).

#include <bits/stdc++.h>
using namespace std;

int countPalindromes(string s)
{
    unordered_map<string, int> m;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!s[i + j])
                break;

            if (s[i - j] == s[i + j])
            {

                if ((i + j + 1) - (i - j) > 1)
                {
                    m[s.substr(i - j, (i + j + 1) - (i - j))]++;
                }
            }
            else
                break;
        }

        for (int j = 0; j <= i; j++)
        {
            if (!s[i + j + 1])
                break;
            if (s[i - j] == s[i + j + 1])
            {
                if ((i + j + 2) - (i - j) > 1)
                {
                    m[s.substr(i - j, (i + j + 2) - (i - j))]++;
                }
            }
            else
                break;
        }
    }

    return m.size();
}
int main()
{
    string s = "abc";
    cout << countPalindromes(s) << endl;
    return 0;
}