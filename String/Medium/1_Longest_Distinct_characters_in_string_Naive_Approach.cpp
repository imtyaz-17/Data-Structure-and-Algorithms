// Length of the longest substring without repeating characters
// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

// Naive Approach
// Time Complexity: O(n^3) ) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
bool areDistinct(string str, int i, int j)
{
    vector<bool> visited(26);
    for(int k =i;k<=j;k++){
        if(visited[str[k]-'a'] == true){
            return false;
        }
        visited[str[k]-'a']=true;
    }

    return true;
}
int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (areDistinct(str, i, j))
            {
                result = max(result, j-i+1);
            }
        }
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
