#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

/*List of deliverables (code to upload to GitHub) as of last class-

1. Implementation of a Linked List: Given a set of values (assume int), create a linked list from them
2. Reversing a Linked List: Given a Linked List, reverse it
3. Chunk Reversing a Linked List for any chunk size in range 1 to n (inclusive): 
    Given a Linked List, and an integer k representing the chunk size, chunk-reverse the list 
4. Selection Sort Algorithm: Given an array of values (assume int), use selection sort to sort them

For each of these problems, your program should be generalised, 
i.e., all parameters (such as size of list, values, size of chunk) should be user input. 
You can either use stdin (scanf command) or read from a .txt file (using something like freopen). 
Remember to check for edge cases. Example: Check what your code does if the list given to reverse is empty.

---

- Implement Selection Sort with Arrays and Linked Lists
- Implement Insertion Sort with Arrays and Linked Lists
- Implement Quick Sort with Arrays and Linked Lists
- Implement insert() and extract_min() operations given a heap in the form of an array
*/


/*
Remaining:
- Playing around with Pointers and Arrays 

Soon after:
- AVL trees


Stuff that doesnt work:
Array quicksort
LL quicksort
LL insort
LL chunk reversal
Node Btree basic
Node Btree Reversal
Linked List Quicksort with doubly linked list


*/

int *RandArray(int n) 
{  
    int i; 
	int *t = malloc( n * sizeof(int) ); // alloting memory equal to the amount of space needed for n integers
	for(i=0; i<n; i+=1) 
	{
		t[i] = (rand() % 100); // each term of the array is set to equal its index
	}
	return t;
}

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

void QuickSortArray(int *a, int i, int j) // figure this out
{
	if (i == j) // if the the input is 1,then do nothing
	{
		return;
	}
	int pivot = (j-i); // make the last term the pivot
	int q, high, r, low;

	while (high < low)
	{
		for(q = i; q < (j-1); q ++) // set value of high to leftmost index greater than pivot value
		{
			if (a[q] > a[pivot])
			{
				high = q;
				break;
			}
		}

		for(r = (j-2); r > i; r -= 1) // set value of low to rightmost index less than pivot value
		{
			if (a[r] <= a[pivot])
			{
				low = r;
				break;
			}
		}
		swapArrayterms(a, high, low);
	}

	swapArrayterms(a, pivot, high);
	QuickSortArray(a, i, low);
	QuickSortArray(a, high, j);
	// take a random number and compare all terms to left and right of that number
	// do this recursively 
}

int *MaxHeapify(int *a, int n) // turns anything to a max ehap
{
	
	for (int i = (n-1); i >= 0; i--)
	{
		if (((2*i + 1)< (n-i)) && (a[i] < a[2*i + 1]))
		{
			swapArrayterms(a,i,2*i + 1);
		}
		if (((2*i + 2)< (n-i)) && (a[i] < a[2*i + 2]))
		{
			swapArrayterms(a,i,2*i + 2);
		}
	}
	return a;
}

void HeapSortArray(int *a, int n) // max heap sort
{
	for (int i = 0; i < n; i++)
	{
		MaxHeapify(a, n-i);
		printf("%d", a[0]);
		swapArrayterms(a, 0, n-i);
		printArray(a,n);
	}
}

int main(int argc, char **argv) { // function main which calls the other functions
	int *a;
	int n;
	scanf("%d", &n);
	a = makeArray(n);
	HeapSortArray(a, n);
	printArray(a,n);
	free(a); // free function after the malloc done by function countArray
	return 0;
}

