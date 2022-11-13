// Subset Sums
// https://practice.geeksforgeeks.org/problems/subset-sums2234/

// Print sums of all subsets of a given set:: Time Complexity: O(2^N)  Space: O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sum = {0};

        for (int i = 0; i < N; i++)
        {
            int sz = sum.size();
            for (int j = 0; j < sz; j++)
            {
                sum.push_back(sum[j] + arr[i]);
            }
        }

        return sum;
    }

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        
        vector<int> ans = subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}