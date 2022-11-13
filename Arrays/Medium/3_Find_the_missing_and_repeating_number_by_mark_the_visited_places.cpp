//Find the missing and repeating number
//https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

//Use elements as Index and mark the visited places
//Time Complexity: O(n) , Auxiliary Space: O(1)
#include <bits/stdc++.h>
using namespace std;

void printMissing_RepeatingElements(int arr[], int sz){
    cout << "The repeating element is ";
    for (int  i = 0; i < sz; i++)
    {
        if (arr[abs(arr[i])-1]>0)
        {
            arr[abs(arr[i])-1]= - arr[abs(arr[i])-1];
        }else{
            cout<<abs(arr[i])<<endl;
        }
    }
     cout << "and the missing element is ";
     for (int i = 0; i < sz; i++)
     {
        if(arr[i]>0)
            cout<<(i+1);
     }
     
    
}
int main()
{
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    printMissing_RepeatingElements(arr, sz);
}
 