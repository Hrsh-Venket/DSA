#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

int *mergeArrays(int n, int *a, int m, int *b)
{
	int *t = malloc((n + m) * sizeof(int));

	for (int i = 0; i < (n); i++)
	{
		t[i] = a[i];
	}

	for (int i = 0; i < m; i++)
	{
		t[i+n] = b[i];
	}
	return t;
}

int *splitArrayL(int n, int *a, int j) 
{
	int *t = malloc(j * sizeof(int));

	for (int i = 0; i < j; i ++)
	{
		t[i] = a[i];
	}
	return t;
}

int *splitArrayR(int n, int*a, int j)
{
	int *t = malloc(j * sizeof(int));

	for (int i = j; i < n; i++)
	{
		t[j-i] = a[i];
	}
    return t;
}

int *QuickSortArray(int *a, int n) // figure this out
{
    if (n == 1) // if the the input is 1,then do nothing
	{
		return a;
	}
    
    int pivot = (n-1);
	int high = 0;
	int low = (n-2);

	while (high < low)
	{
		for(int i = 0; i < (n-1); i ++) // set value of high to leftmost index greater than pivot value
		{
			if (a[i] > a[pivot])
			{
				high = i;
				break;
			}
		}

		for(int i = (n-2); i > 0; i --) // set value of low to rightmost index less than pivot value
		{
			if (a[i] <= a[pivot])
			{
				low = i;
				break;
			}
		}
		swapArrayterms(a, high, low);
	}
    swapArrayterms(a, pivot, high);
	pivot = high;
	

    int sizel = pivot;
    int *l = QuickSortArray(splitArrayL(n, a, sizel), sizel);
    int sizer = (n-pivot);
    int * r = QuickSortArray(splitArrayR(n, a, sizer), sizer);

    return mergeArrays(sizel, l, sizer, r);
}

int main(int argc, char **argv) { // function main which calls the other functions
	int *a;
	int n;
	scanf("%d", &n);
	a = makeArray(n);
    a = QuickSortArray(a, n);
	printArray(a,n);

	free(a); // free function after the malloc done by function countArray
	return 0;
}