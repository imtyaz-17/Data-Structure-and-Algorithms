// Maximum and minimum of an array using minimum number of comparisons
//  https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// Maximum and minimum of an array by comparing in pairs:   [*** Best Method ***]
#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int max;
    int min;
};

struct Pair getMinMax(int arr[], int sz)
{
    struct Pair minmax;
    int i;
    if (sz % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.min = arr[1];
            minmax.max = arr[0];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }

        i = 2;
    }
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];

        i = 1;
    }

    while (i < sz - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
                minmax.max = arr[i];

            if(arr[i+1]< minmax.min)
            minmax.min = arr[i+1];
        }else{
            if (arr[i+1] > minmax.max)
                minmax.max = arr[i+1];

            if(arr[i]< minmax.min)
            minmax.min = arr[i];
        }

        i+=2;
    }

    return minmax;
}

int main()
{
    int arr[] = {1000, 445, 1, 330, 5000, 11};
    int sz = sizeof(arr) / sizeof(arr[0]);

    struct Pair minmax = getMinMax(arr, sz);

    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    return 0;
}