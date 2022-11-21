// Check whether two Strings are anagram of each other
// https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/

// by storing all characters in HashMap
// Time Complexity: O(n) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b)
{
    if (a.length() != b.length())
        return false;
    unordered_map <char, int> Map;

    for(int i =0;i<a.length();i++){
        Map[a[i]]++;
    }
    for (int  i = 0; i < b.length(); i++)
    {
        if(Map.find(b[i]) != Map.end()){
            Map[b[i]] -= 1;
        }else{
            return false;
        }
    }

    for(auto items: Map){
        if(items.second !=0)
        return false;
    }

    return true; 
    
}
int main()
{
    string str1 = "gram";
    string str2 = "arm";

    if (isAnagram(str1, str2))
        cout << "The two strings are anagram of each other"
             << endl;
    else
        cout << "The two strings are not anagram of each "
                "other"
             << endl;
}