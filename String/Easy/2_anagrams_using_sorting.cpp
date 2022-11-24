// Check whether two Strings are anagram of each other
// https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/

// using sorting
// Time Complexity: O(N * logN) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for(int i =0;i<n1;i++){
        if(str1[i ]!= str2[i]){
            return false;
        }
    }

    return true;
}
int main()
{
    string str1 = "gram";
    string str2 = "arm";

    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";

    return 0;
}