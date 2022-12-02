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

void SelSortArray(int *a, int n) 
{
    int i;
    int q;
    int min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (q = 0; q < n; q++)
        {
            if (a[min] < a[q])
            {
                min = q;
            }
        swapArrayterms(a, min, i);
        }
        // swap qth term with term in ith place
    }
}

int main(int argc, char **argv) { // function main which calls the other functions
	int *a;
	int n;
	scanf("%d", &n);
	a = makeArray(n);
	SelSortArray(a,n);
	printArray(a,n);

	free(a); // free function after the malloc done by function countArray
	return 0;
}