// Find all distinct palindromic sub-strings of a given string
// https://www.geeksforgeeks.org/find-number-distinct-palindromic-sub-strings-given-string/

// using modified Manacher’s algorithm
// Time Complexity: O(n^2) , Auxiliary Space: O().
#include <iostream>
#include <map>
using namespace std;

void palindromeSubStrs(string s)
{
    map<string, int> m;
    int n = s.size();

    int table[2][n + 1];
    s = "@" + s + "#";
    for (int j = 0; j <= 1; j++)
    {
        int rp = 0;
        table[j][0] = 0;

        int i = 1;
        while (i <= n)
        {
            while (s[i - rp - 1] == s[i + j + rp])
            {
                rp++;
            }

            table[j][i] = rp;
            int k = 1;
            while ((table[j][i - k] != rp - k) && (k < rp))
            {
                table[j][i + k] = min(table[j][i - k], rp - k);
                k++;
            }
            rp = max(rp - k, 0);
            i += k;
        }
    }

    s = s.substr(1, n);

    m[string(1, s[0])] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int rp = table[j][i]; rp > 0; rp--)
                m[s.substr(i - rp - 1, 2 * rp + j)] = 1;

            m[string(1, s[i])] = 1;
        }
    }
    cout << " palindrome sub-strings";
    map<string, int>::iterator ii;
    for (ii = m.begin(); ii != m.end(); ++ii)
        cout << (*ii).first << endl;
}
int main()
{
    palindromeSubStrs("abaaa");
    return 0;
}