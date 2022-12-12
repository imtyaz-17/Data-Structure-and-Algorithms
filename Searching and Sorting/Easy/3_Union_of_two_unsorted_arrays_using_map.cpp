// Find Union and Intersection of two unsorted arrays
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

// Using map
// Time Complexity:  O(m * log(m) + n * log(n))  , Auxiliary Space: O(max(m + n)).

#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp.insert({a[i], i});
    }
    for (int i = 0; i < m; i++)
        mp.insert({b[i], i});

    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout<< itr->first <<" ";
    }
}
int main()
{
    int a[9] = {1, 2, 5, 6, 2, 3, 5, 7, 3};
    int b[10] = {2, 4, 5, 6, 8, 9, 4, 6, 5, 4};

    getUnion(a, 9, b, 10);
}