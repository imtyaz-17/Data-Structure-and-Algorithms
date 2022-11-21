// Recursively remove all adjacent duplicates
// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/

//
// Time Complexity: O(n) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string remv(string s)
    {
        string ans;
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            if (i < n - 1 && s[i] == s[i + 1])
            {
                while (i < n - 1 && s[i] == s[i + 1])
                {
                    i++;
                }
            }
            else
            {
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
    string rremove(string s)
    {
        // code here
        string s1;
        while (s.size() != s1.size())
        {
            s1 = s;
            s = remv(s);
        }
        return s;
    }
};

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}