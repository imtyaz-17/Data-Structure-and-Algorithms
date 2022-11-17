// Find the missing and repeating number
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/

// Using Map
// Time Complexity: O(n) , Auxiliary Space: O(1)
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        unordered_map<int, bool> mp;

        int *res = new int[2];

        for (int  i =0;i<n; i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = true;
            }
            else
            {
                //cout << "Repeating;
                res[0]= arr[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp.find(i) == mp.end())
            {
                res[1] = i;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends