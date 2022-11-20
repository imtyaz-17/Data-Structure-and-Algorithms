// Sentence Palindrome (Palindrome after removing spaces, dots, .. etc)
// https://www.geeksforgeeks.org/sentence-palindrome-palindrome-removing-spaces-dots-etc/

// compare each character from left and right.
// Time Complexity: O(n) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std;

bool sentencePalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;

    for (int i = 0; i <= right; i++)
        str[i] = tolower(str[i]);
    while (left <= right)
    {
        if(!((str[left] >='a' && str[left] <='z') || (str[left] >='0' && str[left] <='9'))){
	            left++;
	        }
	        else if(!((str[right] >='a' && str[right] <='z' )|| (str[right] >='0' && str[right] <='9'))){
	            right--;
	        }
        else if(str[left] == str[right]){
            left++;
            right--;
        }
        else
        return false;
    }

    return true;
}
int main()
{
    string str = "0P";

    if (sentencePalindrome(str))
        cout << "Sentence is palindrome.";
    else
        cout << "Sentence is not palindrome.";

    return 0;
}