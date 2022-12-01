#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

// stack implementation

// create a stack is basically creating an array

int *makeStack(int n)
{
	int *t = malloc(n * sizeof(int)); 

	for (int i = 0; i < n; i ++)
	{
		scanf("%d", &t[i]);
	}
	return t;
}

void printStack(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf( "%d ", a[i]); // print each term with a comma before
	}
	printf("\n"); // print full stop and newline character
}

void *popStack(int *s, int n) // remove the top term from the array
{
    s = realloc(s, ((n-1) * sizeof(int)));
}

void *pushStack(int *s, int n, int x)
{
    s = realloc(s, ((n+1) * sizeof(int)));
    s[n] = x;
}

int main()
{
	int *a;
	int n;
	scanf("%d", &n);
	a = makeStack(n);

	printStack(a,n);

    a = popStack(a, n);
    n --;

	printStack(a,n);


    int x; // enter the term you want to push to the stack
    scanf("%d", &x);
    pushStack(a, n, x);


	printStack(a,n+1);

	free(a); // free function after the malloc done by function countArray
	return 0;
}
