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



int main(int argc, char **argv) { // function main which calls the other functions
	int *a;
	int n;
	scanf("%d", &n);
	a = makeArray(n);
	printArray(a,n);

	free(a); // free function after the malloc done by function countArray
	return 0;
}