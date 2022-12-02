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

void InSortArray(int*a, int n) 
{
	if (a[1] < a[0]) 
	{
		swapArrayterms(a, 0, 1);
	}
	for (int i=2; i<n; i++)
	{
		int q;
		for (q=0; q<i; q++) // loop through the terms before a[i] and find where to place a[i]
		{
			if (a[i] <= a[q]) {break;}
		}
		int temp = a[i];
		for (int r = i; r > q; r-=1) // shift functions forward
		{
			a[r] = a[r-1];
		}
		a[q] = temp;
	}
	// compare first two terms and order them
	// bring in the next term iteratively and place them between the sorted terms
}

int main(int argc, char **argv) { // function main which calls the other functions
	int *a;
	int n;
	scanf("%d", &n);
	a = makeArray(n);
	InSortArray(a,n);
	printArray(a,n);

	free(a); // free function after the malloc done by function countArray
	return 0;
}