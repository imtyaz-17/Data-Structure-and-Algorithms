// Given a sequence of words, print all anagrams together
// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/?ref=lbp

// Using vector of pair
// Time Complexity: O(NMLogM + MNLogN) , Auxiliary Space: .

#include <bits/stdc++.h>
using namespace std;

void createDuplicateArray(vector<pair<string, int>> &dupArray, vector<string> &wordAr, int size)
{
    for (int i = 0; i < size; i++)
    {
        dupArray.push_back(make_pair(wordAr[i], i));
    }
}
void printAnagramsTogether(vector<string> &wordArr, int size)
{
    vector<pair<string, int>> dupArray;
    createDuplicateArray(dupArray, wordArr, size);

    int i;
    for (i = 0; i < size; i++)
    {
        sort(dupArray[i].first.begin(), dupArray[i].first.end());
    }

    sort(dupArray.begin(), dupArray.end());

    for (i = 0; i < size; ++i)
        cout << wordArr[dupArray[i].second] << " ";
}
int main()
{
    vector<string> wordArr = {"cat", "dog", "tac", "god", "act"};
    printAnagramsTogether(wordArr, wordArr.size());
    return 0;
}