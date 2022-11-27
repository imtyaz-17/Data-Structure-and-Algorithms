// Count All Palindrome Sub-Strings in a String | Set 2
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string-set-2/

// using Two pointer
// Time Complexity: O(n^2) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int countPalindromes(string s)
{
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i - 1;
        int right = i + 1;

        while (left >= 0 && right < n)
        {
            if (s[left] == s[right])
                count++;
            else
                break;

            left--;
            right++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int left = i;
        int right = i + 1;

        while (left >= 0 && right < n)
        {
            if (s[left] == s[right])
                count++;
            else
                break;
            left--;
            right++;
        }
    }

    return count;
}
int main()
{
    string s = "aaa";
    cout << countPalindromes(s) << endl;
    return 0;
}