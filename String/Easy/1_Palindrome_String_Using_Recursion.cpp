// C Program to Check if a Given String is Palindrome
// https://www.geeksforgeeks.org/c-program-check-given-string-palindrome/

// Using Recursion
// Time Complexity: O(n) , Auxiliary Space: O(1).

#include <bits/stdc++.h>
using namespace std; 

int isPalindrome(char *str, int l, int r)
{
	if (str == NULL || l < 0 || r < 0)
	{
		return 0;
	}
	if (l >= r)
	{
		return 1;
	}
	if (str[l] == str[r])
	{
		return isPalindrome(str, l + 1, r - 1);
	}
	return 0;
}
int main()
{
	char s[] = {"abbba"};
	int i = 0, n = sizeof(s) / sizeof(s[0]);

	if (isPalindrome(s, i, strlen(s) - 1))
		printf("%s is palindrome", s);
	else
		printf("%s is not palindrome", s);
}