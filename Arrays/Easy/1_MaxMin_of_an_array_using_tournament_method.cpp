// Maximum and minimum of an array using minimum number of comparisons
//  https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// Maximum and minimum of an array using the tournament method:
#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int max;
    int min;
};

Pair getMinMax(int arr[],int low, int high)
{
    struct Pair minmax, mmleft,mmright;

    if(low==high){
        minmax.max = arr[low];
        minmax.min = arr[low];

        return minmax;
    }

    if(high == low +1){
        if(arr[low] > arr[high]){
            minmax.max = arr[low];
            minmax.min = arr[high];
        }else{
            minmax.max = arr[high];
            minmax.min = arr[low];
        }

        return minmax;
    }


    int mid = (low + high) /2;

    mmleft = getMinMax(arr, low, mid);
    mmright = getMinMax(arr, mid+1, high);

    if (mmleft.min < mmright.min)
    {
        minmax.min= mmleft.min;
    }else{
        minmax.min = mmright.min;
    }

     if (mmleft.max > mmright.max)
    {
        minmax.max= mmleft.max;
    }else{
        minmax.max = mmright.max;
    }
    

    return minmax;
}
int main()
{
    int arr[] = {1000, 445, 1, 330, 3000,11};
    int sz =  sizeof(arr)/sizeof(arr[0]);

    struct Pair minmax = getMinMax(arr,0,sz-1);

    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    return 0;
}