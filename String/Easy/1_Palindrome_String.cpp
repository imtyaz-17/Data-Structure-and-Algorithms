// C Program to Check if a Given String is Palindrome
// https://www.geeksforgeeks.org/c-program-check-given-string-palindrome/

// Using the Standard (simple) Method
// Time Complexity: O(n) , Auxiliary Space: O(1).
 
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int l=0;
	    int h= S.size()-1;
	    while(h>l){
	        if(S[l++] !=S[h--]){
	           return 0;
	        }
	    }
	    return 1;
	}

};


int main() 
{
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}