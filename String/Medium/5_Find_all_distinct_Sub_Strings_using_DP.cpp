// Find all distinct palindromic sub-strings of a given string
// https://www.geeksforgeeks.org/find-number-distinct-palindromic-sub-strings-given-string/

// using dynamic programming
// Time Complexity: O(n^2) , Auxiliary Space: O(n^2).

#include <iostream>
#include <vector>
using namespace std;

void palindromeSubStrs(string s)
{
	int n = s.size();
	
	vector<vector<bool> > dp(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
		if (i < n && s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	
	for (int len = 3; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			if (s[i] == s[i + (len - 1)]
				&& dp[i + 1][i + (len - 1) - 1]) {
				dp[i][i + (len - 1)] = true;
			}
		}
	}

	
	vector<int> kmp(n, 0);
	for (int i = 0; i < n; i++) {
		int j = 0, k = 1;
		while (k + i < n) {
			if (s[j + i] == s[k + i]) {
				
				dp[k + i - j][k + i] = false;
				kmp[k++] = ++j;
			}
			else if (j > 0) {
				j = kmp[j - 1];
			}
			else {
				kmp[k++] = 0;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		string str;
		for (int j = i; j < n; j++) {
			str += s[j];
			if (dp[i][j]) {
				
				count++;
				cout << str << '\n';
			}
		}
	}
	cout << "Total number of distinct palindromes is "
		<< count << '\n';
}

int main()
{
	string s1 = "aaa", s2 = "aaaaaaaaaa";
	palindromeSubStrs(s1);
	//palindromeSubStrs(s2);
	return 0;
}

