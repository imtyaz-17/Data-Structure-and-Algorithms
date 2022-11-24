// Length of the longest substring without repeating characters
// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

//  store last index of every character in an array
// Time Complexity: O(n + d) ) , Auxiliary Space: O(d).

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

int longestUniqueSubsttr(string str)
{
    int n = str.size();

    int result = 0;
    vector <int> lastIndex(NO_OF_CHARS, -1);
     int i = 0;

      for (int j = 0; j < n; j++) {
        i = max(i, lastIndex[str[j]] +1);

        result = max(result, j-i+1);

        lastIndex[str[j]]=j;
      }

      return result;
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
