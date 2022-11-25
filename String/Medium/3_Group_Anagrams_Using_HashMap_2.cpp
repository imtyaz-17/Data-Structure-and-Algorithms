// Given a sequence of words, print all anagrams together
// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/?ref=lbp

// Using HashMap with O(NM)
// Time Complexity: O(NM) , Auxiliary Space: O(NM).

#include <bits/stdc++.h>
using namespace std;

void printAnagramsTogether(vector<string> my_list)
{
    map<map<char, int>, vector<string>> my_map;
    for (string str : my_list)
    {
        map<char, int> temp_map;
        vector<string> temp_my_list;

        for (int i = 0; i < str.length(); i++)
        {
            ++temp_map[str[i]];
        }

        auto it = my_map.find(temp_map);
        if (it != my_map.end())
        {
            it->second.push_back(str);
        }
        else
        {
            temp_my_list.push_back(str);
            my_map.insert({temp_map, temp_my_list});
        }
    }

    vector<vector<string>> result;

    for (auto it = my_map.begin(); it != my_map.end(); ++it)
    {
        result.push_back(it->second);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << "]";
    }
}
int main()
{
    vector<string> my_list = {"cat", "dog", "ogd","god", "atc"};
    printAnagramsTogether(my_list);

    return 0;
}