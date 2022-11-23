// Print all the duplicates in the input string
// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Using hashing
// Time Complexity: O(N ) , Auxiliary Space: O(NO_OF_CHARS).

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

void charCounts(char *str, int *count)
{
    for (int i = 0; i < *(str + i); i++)
    {
        count[*(str + i)]++;
    }
}
void printDups(char *str)
{
    int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
    charCounts(str, count);

    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        if(count[i]>1)
         printf("%c, count = %d \n", i, count[i]);
    }
    free(count);
}
int main()
{
    char str[] = "test string";
    printDups(str);
    getchar();
    return 0;
}