// Length of the longest substring without repeating characters
// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

// using the window sliding technique
// Time Complexity: O(n) ) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str)
{
    if (str.length() == 0)
        return 0;

    if (str.length() == 1)
        return 1;

    int maxLength = 0;
    bool visited[256] = {false};
    
    int left = 0, right = 0;

    for(; right<str.length();right++){
        if(visited[str[right]] ==false){
            visited[str[right]]=true;
        }else{
            maxLength = max(maxLength , (right-left));
            
            while (left<right)
            {
                if(str[left] != str[right]){
                    visited[str[left]] =false;
                }else{
                    left++;
                    break;
                }
                left++;
            }
            
        }
    }

     maxLength = max(maxLength, (right - left));

     return maxLength;
}

int main()
{
    string str = "abcabcbb";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}
