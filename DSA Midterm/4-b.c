#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void returnSmallestNum(int *maxHeap, int n)
{
    // here, only the bottom leaf nodes can be the smallest number

    // calculate which indexes to check

    int sum = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        sum += pow(2, i);
        if (sum > n)
        {
            break;
        }
    }
    sum -= pow(2, i);

    // now, we have the index of the first leaf node

    int smallestNum = maxHeap[sum];
    for (int j = sum + 1; j < n; j++)
    {
        if (maxHeap[j] < smallestNum)
        {
            smallestNum = maxHeap[j];
        }
    }
    printf("%d", smallestNum);
}

int main()
{
    // call the function bro. Be a man
}