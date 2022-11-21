// Remove all consecutive duplicates from the string
// https://www.geeksforgeeks.org/remove-consecutive-duplicates-string/

// Remove all consecutive duplicates from the string using Iterative approach:
// Time Complexity: O(N) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    int n = s.length();
    string str = "";
    if (n == 0)
        return str;
    
    for(int i=0;i<n-1;i++){
        if(s[i] != s[i+1]){
            str +=s[i];
        }
    }
    str.push_back(s[n - 1]);
    return str;
}
int main()
{

    string s1 = "geeksforgeeks";
    cout << removeDuplicates(s1) << endl;

    string s2 = "aabaa";
    cout << removeDuplicates(s2) << endl;

    return 0;
}