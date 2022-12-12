// Find Union and Intersection of two unsorted arrays
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

// Using Set
// Time Complexity:  O(max(m,n))  , Auxiliary Space: O(max(m,n)).

#include <bits/stdc++.h>
using namespace std;
// C++ program to find union and intersection
// using sets

#include <bits/stdc++.h>
using namespace std;

void printUnion(int arr1[], int arr2[], int n1, int n2)
{
    set<int> s;

    for (int i = 0; i < n1; i++)
    {
        s.insert(arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        s.insert(arr2[i]);
    }

    cout << "Union:" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";

    cout << endl;
}

void printIntersection(int arr1[], int arr2[], int n1,
                       int n2)
{
    set<int> s;

    for (int i = 0; i < n1; i++)
    {
        s.insert(arr1[i]);
    }

    cout << "Intersection:" << endl;

    for (int i = 0; i < n2; i++)
    {
        if (s.count(arr2[i]))
        {
            cout << arr2[i] << " ";
        }
    }

    cout << endl;
}

int main()
{
    // int arr1[] = {7, 1, 5, 2, 3, 6};
    // int arr2[] = {3, 8, 6, 20, 7};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n1, n2;
    cin >> n1 >> n2;
     int arr1[n1],arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[n1];
    }

    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[n2];
    }

    printUnion(arr1, arr2, n1, n2);
    printIntersection(arr1, arr2, n1, n2);
}