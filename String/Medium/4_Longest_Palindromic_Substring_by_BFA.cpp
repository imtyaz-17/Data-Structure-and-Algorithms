// Longest Palindromic Substring using Dynamic Programming
// https://www.geeksforgeeks.org/longest-palindromic-substring-using-dynamic-programming/

//  Brute Force Approach
// Time Complexity: O(n^3) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i]; 
}
int longestPalSubstr(string str)
{
    int n = str.size();

    int maxLength = 1, start = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++)
            {
                if(str[i+k] !=str[j-k]){
                    flag =0;
                }
            }

            if(flag && (j-i+1)>maxLength){
                start= i;
                maxLength = j-i+1;
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
    return maxLength;
}
int main()
{
    string str = "forgeeksskeegfor";
   int  l=longestPalSubstr(str);
    cout << "\nLength is: "<<l<<endl;
    return 0;
}