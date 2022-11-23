// Print all the duplicates in the input string
// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Using Maps
// Time Complexity: O(N*log(N ) , Auxiliary Space: O(K).

#include <bits/stdc++.h>
using namespace std;

void printDups(string str)
{
    map<char, int> countchar;
    for (int i = 0; i < str.length(); i++)
    {
        countchar[str[i]]++;
    }
    for(auto it: countchar){
        if(it.second >1){
            cout<<it.first<<", count = " << it.second<<endl;
        }
    }

}
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}