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

	for (int i = 0; i < (n-j); i++)
	{
		t[i] = a[j-i];
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
		if (a[high] < a[pivot])
		{
			high++;
		}
		else if (a[low] > a[pivot])
		{
			low--;
		}
		else
		{
			swapArrayterms(a, high, low);
		}
	}
	if (a[high] > a[pivot])
	{
		swapArrayterms(a, high, pivot);
	}
	else
	{
		swapArrayterms(a, high+1, pivot);
	}
	int *left = splitArrayL(n, a, high);
	int *right = splitArrayR(n, a, high);
	int *leftSorted = QuickSortArray(left, high);
	int *rightSorted = QuickSortArray(right, n-high);
	int *sorted = mergeArrays(high, leftSorted, n-high, rightSorted);
	return sorted;
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