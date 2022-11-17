// Find the missing and repeating number
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// Make two equations using sum and sum of squares
// Time Complexity: O(n) , Auxiliary Space: O(1)

#include <bits/stdc++.h>

using namespace std;

vector<int> repeated_Miss_Number(vector<int> &nums)
{
    int len = nums.size();
    long long int sumN = (len * (len + 1)) / 2;
    long long int sumNSqr = (len * (len + 1) *(2*len +1) )/6;

    for (int i = 0; i < len; i++)
    {
        sumN -=  nums[i];
        sumNSqr -=(nums[i] * nums[i]);
    }

    int missing, repeating;

    missing= (sumN + sumNSqr/sumN)/2;
    repeating = missing -sumN;

    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}
int main()
{

    vector<int> nums = {4, 3, 6, 2, 1, 6, 7};
    vector<int> ans = repeated_Miss_Number(nums);
    for (int x : ans)
    {
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}
