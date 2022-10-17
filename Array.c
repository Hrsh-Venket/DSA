#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * countArray(int n) {  
    int i; 
	int *t = malloc( n * sizeof(int) ); // alloting memory equal to the amount of space needed for n integers
	if(t) {
		for(i=0; i<n; i+=1) {t[i] = i;} // each term of the array is set to equal its index
	}
	return t;
}


void printArray(int *a, int n) {
	printf("Array = %d", a[0]); // first term printed here because it should not print a comma before
	for(int i=1; i<n; i+=1) {
		printf( ", %d", a[i]); // print each term with a comma before
	}
	printf(".\n"); // print full stop and newline character
}

int main(int argc, char **argv) { // function main which calls the other functions
	int *a;
	int n = 11;

	a = countArray(n);
	printArray(a,n);

	free(a); // free function after the malloc done by function countArray
	return 0;
}
