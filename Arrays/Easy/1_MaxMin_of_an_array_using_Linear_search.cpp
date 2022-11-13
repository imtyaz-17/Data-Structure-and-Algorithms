// Maximum and minimum of an array using minimum number of comparisons
//  https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// Maximum and minimum of an array using Linear search
#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int max;
    int min;
};

Pair getMinMax(int arr[],int sz)
{
    struct Pair minmax;
    
    if (sz == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];

        return minmax;
    }

    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > minmax.max)
        {
            minmax.max = arr[i];
        }
        else if (arr[i] < minmax.min)
        {
            minmax.min = arr[i];
        }
    }

    return minmax;
}
int main()
{
    int arr[] = {1000, 445, 1, 330, 3000,11};
    int sz =  sizeof(arr)/sizeof(arr[0]);
    struct Pair minmax = getMinMax(arr,sz);
    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    return 0;
}