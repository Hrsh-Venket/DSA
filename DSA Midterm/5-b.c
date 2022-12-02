#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>


// this is still not working but I think my logic is correct
//gcc -g3 -Wall [filename.c]

int *makeArray(int n)
{
	int *t = malloc(n * sizeof(int)); 

	for (int i = 0; i < n; i ++)
	{
		scanf("%d", &t[i]);
	}
	return t;
}

void printArray(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf( "%d ", a[i]); // print each term with a comma before
	}
	printf("\n"); // print full stop and newline character
}

void swapArrayterms(int*a, int i, int j)
{
	if (i == j)
	{
		return;
	}
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

int *sortEveryThirdElement(int *a, int n)
{
    int nsort = n / 3; // the number of terms that need to be sorted
    
    for (int q = 0; q < nsort; q++)
    {
        int min = (2 + (3 * q));
        for (int i = 0; i < nsort; i++)
        {
            if (a[2 + (3 * i)] < a[min])
            {
                min = (2 + (3 * i));
            }
            
        }
        swapArrayterms(a, min, 2);
    }
}


int *removeFirstArrayElement(int*a, int n)
{
    int *t = (int *)malloc((n-1) * sizeof(int));
    for (int i = 1; i < n; i++)
    {
        t[i-1] = a[i];
    }
    return t;
}

void minheapify(int *a, int n)
{
    int start = (n / 2) + 1;

    for (int i = start; i >= 0; i--)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min = i;
        if ((left < n) && (a[left] < a[min]))
        {
            min = left;
        }
        if ((right < n) && (a[right] < a[min]))
        {
            min = right;
        }
        if (min != i)
        {
            swapArrayterms(a, i, min);
        }
    }
}

void kSmallestAmongUntouched(int *a, int k, int n)
{
    // make a heap of the untouched elements, in a separate array
    int untouched = n - ((n+1) / 3) - 3;
    int *heap = (int *)malloc(untouched * sizeof(int));
    int heapindex = 0;
    for (int i = 0; i < untouched; i++)
    {
        if (i % 3 != 2)
        {
            heap[heapindex] = a[i];
            heapindex ++;  
        }
    }

    printf("The untouched elements are \n");
    printArray(heap, untouched);

    for (int i = 0; i < k; i++)
    {
        minheapify(heap, (untouched-i));
        printf("%d ", heap[0]);
        heap = removeFirstArrayElement(heap, (untouched-i));
    }
    // k times
        // min heapify the heap
        // print the first element of the heap
        // remove the first element of the heap
}


int main()
{
    int *a;
    int n, k;
    printf("Enter the number of terms in the array: \n");
    scanf("%d", &n);

    printf("Enter the terms of the array as space-separated integers: \n");
    a = makeArray(n);
    
    printf("The array after every 3rd element is sorted is: \n");
    sortEveryThirdElement(a, n);
    printArray(a, n);
    
    printf("Enter k \n");
    scanf("%d", &k);
    
    printf("The k smallest elements are: \n");
    kSmallestAmongUntouched(a, k, n);
    return 0;
}


// struct node * *a

// int a[] = {}

// int *a = malloc(10 * sizeof(int))
