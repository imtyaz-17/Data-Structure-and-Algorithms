// Remove all consecutive duplicates from the string
// https://www.geeksforgeeks.org/remove-consecutive-duplicates-string/

// Remove all consecutive duplicates from the string using recursion:
// Time Complexity: O(N2 ) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(char *S)
{
    if (S[0] == '\0')
        return;
    if (S[0] == S[1])
    {
        int i = 0;
        while (S[i] != '\0')
        {
            S[i] = S[i + 1];
            i++;
        }
        removeDuplicates(S);
    }

    removeDuplicates(S + 1);
}
int main()
{
    char S1[] = "geeksforgeeks";
    removeDuplicates(S1);
    cout << S1 << endl;

    char S2[] = "aabcca";
    removeDuplicates(S2);
    cout << S2 << endl;

    return 0;
}