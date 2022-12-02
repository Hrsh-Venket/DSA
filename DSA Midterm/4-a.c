#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void thirdLargestNum(int *maxHeap, int n)
{
    // third largest num is at index 1 or 2

    if (n <= 2)
    {
        printf("Third largest number is %d", NULL);
    }
    else if (n < 6)
    {
        int min = 1;
        for (int i = 1; i < n; i++)
        {
            if (maxHeap[i] < maxHeap[min])
            {
                min = i;
            }
        }
        printf("Third largest number is %d", maxHeap[min]);
    }
    else
    {
        int min = 1;
        for (int i = 1; i < 6; i++)
        {
            if (maxHeap[i] < maxHeap[min])
            {
                min = i;
            }
        }
        printf("Third largest number is %d", maxHeap[min]);
    }
}