// Find the missing and repeating number
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// Use Map
// Time Complexity: O(n) , Auxiliary Space: O(1)
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int sz = 6;

    unordered_map<int , bool> mp;

    for (int  i : arr)
    {
        if (mp.find(i) == mp.end())
        {
            mp[i] = true;
        }
        else{
            cout << "Repeating = " << i;
        }
        
    }
    cout << endl;
    for(int i = 1; i <= sz; i++)
    {
        if (mp.find(i) == mp.end())
        {
            cout << "Missing = " << i;
        }
    }
    
    return 0;
}
