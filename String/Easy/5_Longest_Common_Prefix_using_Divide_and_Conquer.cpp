// Longest Common Prefix using Divide and Conquer Algorithm
// https://www.geeksforgeeks.org/longest-common-prefix-using-divide-and-conquer-algorithm/

// using Divide and Conquer Algorithm
// Time Complexity: O(N M) , Auxiliary Space: O(M Log N).

#include <bits/stdc++.h>
using namespace std;

string CommonPrefix(string s1, string s2)
{
    string result;

    int n1 = s1.length(), n2= s2.length();

    for (int i = 0,j=0; i<=n1-1 && j<=n2-1; i++,j++)
    {
        if(s1[i] != s2[j])
        break;

        result+=s1[i];
    }

    return result;
    
}
string longestCommonPrefix(string arr[], int low ,int high)
{
    if(low==high)
    return arr[low];

    if(high >low){
        int mid = low+ (high -low)/2;

        string str1 = longestCommonPrefix(arr, low, mid);
        string str2 = longestCommonPrefix(arr, mid+1, high);

        return CommonPrefix(str1,str2);
    }
    
}

int main()
{
     string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof (arr) / sizeof (arr[0]);
 
    string ans = longestCommonPrefix(arr, 0, n-1);
 
    if (ans.length())
        cout << "The longest common prefix is "
             << ans;
    else
        cout << "There is no common prefix";
    return (0);
}