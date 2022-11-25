// Given a sequence of words, print all anagrams together
// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/?ref=lbp

// Using hashmap
// Time Complexity: O(M+N) , Auxiliary Space: O(MxN).

#include <bits/stdc++.h>
using namespace std;

void printAnagramsTogether(string arr[], int size)
{
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < size; i++)
    {
        string word = arr[i];

        char letters[word.size() + 1];
        strcpy(letters, word.c_str());

        sort(letters, letters + word.size() + 1);

        string newWord;

        for (int i = 0; i <= word.size(); i++)
        {
            newWord += letters[i];
        }

        if (map.find(newWord) != map.end())
        {
            map[newWord].push_back(word);
        }
        else
        {
            vector<string> words;
            words.push_back(word);
            map[newWord] = words;
        }
    }

    unordered_map<string, vector<string>>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        vector<string> values = map[it->first];
        if(values.size()>1){
            cout<<"[";
            for(int i=0;i<values.size() -1;i++){
                cout<<values[i]<<",";
            }
            cout<<values[values.size() -1];
            cout<<"]";
        }
    }
}
int main()
{
    string arr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAnagramsTogether(arr, size);

    return 0;
}