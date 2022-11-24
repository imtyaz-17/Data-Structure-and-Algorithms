// Print Longest substring without repeating characters
// https://www.geeksforgeeks.org/print-longest-substring-without-repeating-characters/

// using  hash table
// Time Complexity: O(n) , Auxiliary Space: O(n).

#include <bits/stdc++.h>
using namespace std;

string findLongestSubstring(string str)
{
    int i;
    int n = str.length();

    int st = 0;
    int currentlen;
    int maxLength = 0;

    int start;

    unordered_map<char, int> position;

    position[str[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        if (position.find(str[i]) == position.end())
        {
            position[str[i]] = i;
        }
        else
        {
            if (position[str[i]] >= st)
            {
                currentlen = i - st;
                if (maxLength < currentlen)
                {
                    maxLength = currentlen;
                    start = st;
                }

                st = position[str[i]] + 1;
            }

            position[str[i]] = i;
        }
    }

    if (maxLength < i - st)
    {
        maxLength = i - st;
        start = st;
    }


    return str.substr(start,maxLength);
}

int main()
{
    string str = "GEEKSFORGEEKS";
    cout << findLongestSubstring(str);
    return 0;
}
