// Longest Common Prefix using Sorting
// https://www.geeksforgeeks.org/longest-common-prefix-using-sorting/

// using Sorting
// Time Complexity: O(MAX * n * log n ) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(string ar[], int n)
{
    if (n == 0)
        return "";

    sort(ar, ar + n);

    int len = min(ar[0].size(), ar[n - 1].size());

    string first = ar[0], last = ar[n - 1];

    int i = 0;
    while(i< len && first[i] == last[i]){
        i++;
    }

    string prefix =first.substr(0,i);

    return prefix;
}
int main()
{
    string ar[] = {"flower","flow","flight"};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "The longest common prefix is: "
         << longestCommonPrefix(ar, n);
    return 0;
    return (0);
}