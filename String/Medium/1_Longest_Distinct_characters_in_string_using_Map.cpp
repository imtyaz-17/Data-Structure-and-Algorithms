// Length of the longest substring without repeating characters
// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

// using Map
// Time Complexity: O(n + d) ) , Auxiliary Space: O(d).

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str)
{
    map<char, int> seen;

    int maximum_length = 0;

    int start = 0;
    for(int end = 0; end < str.length(); end++){
        if(seen.find(str[end]) != seen.end()){
            start =max(start, seen[str[end]]+1);
        }

        seen[str[end]] = end;

        maximum_length = max(maximum_length, end - start +1);
    }
    return maximum_length;
}

int main()
{
    string str = "geeksforgeeks";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}
