// Maximum length substring having all same characters after k changes
// https://www.geeksforgeeks.org/maximum-length-substring-having-all-same-characters-after-k-changes/

// check for each character
// Time Complexity: O(n) ) , Auxiliary Space: O(1).

#include <iostream>
using namespace std;
int findLength(string &A, int n, int k, char ch)
{
    int maxLength = 1;
    int cnt = 0;
    int left = 0, right = 0;
    while (right < n)
    {
        if (A[right] != ch)
        {
            ++cnt;
        }
        while (cnt > k)
        {
            if (A[left] != ch)
                --cnt;

            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
        ++right;
    }
    return maxLength;
}
int answer(string &A, int n, int k)
{
    int maxLength = 1;

    for (int i = 0; i < 26; i++)
    {
        maxLength = max(maxLength, findLength(A, n, k, i + 'A'));
        maxLength = max(maxLength, findLength(A, n, k, i + 'a'));
    }
    return maxLength;
}
int main()
{
   string s;
		cin >> s;
		int k;
		cin >> k;
 int n=s.length();
    cout << "Maximum length = " << answer(s, n, k) << endl;
    return 0;
}