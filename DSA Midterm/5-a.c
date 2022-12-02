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

int main(int argc, char **argv) { // function main which calls the other functions
    int *a;
    int n;
    printf("Enter the number of terms in the array: \n");
    scanf("%d", &n);
    printf("Enter the terms of the array as space-separated integers: \n");
    a = makeArray(n);
    sortEveryThirdElement(a, n);
    printArray(a, n);
    return 0;
}