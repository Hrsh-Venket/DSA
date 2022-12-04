#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>


// queue implementation

// _ _ _ _ _ 
// keep track of queue addres, start, max, n
// start = 0
// n = 0
// max = 5
// pop from start index
//    increase start by 1
//    decrease max by 1
// where to insert: 
//    (start + n) % max
//    increase n by 1
// 

struct queue {
    int *data;
    int start;
    int n;
    int max;
};

void pushQueue(struct queue *a)
{
    if ((a->n) >= (a->max))
    {
        printf("the a is full\n");
        return;
    }
    int x, insert;
    insert = ((a->start) + (a->n)) % (a->max);
    scanf("%d", &x);
    a->data[insert] = x;
    (a->n)++;
}

int popQueue(struct queue *a)
{
    int pop = (a->data)[(a->start)];
    (a->start)++;
    (a->n)--;
    return pop;
}

// function has some issue
void printArray(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf( "%d ", a[i]); // print each term with a comma before
	}
	printf("\n"); // print full stop and newline character
}

void printQueue(struct queue *a )
{
    for (int i = (a->start); i < (a->n); i++)
    {
       // printf("%d", *((a->data)+(i % (a->max))) );
        printf("%d", (a->data)[(i % (a->max)]);
    }
    // print as array from start
    // print as  // a[I]
}

// void printQueue(struct queue *a)
// {
//     int print = (a->start);
//     for (int i; i < (a->n); i++)
//     {
//         printf("%d ", (a->data)[(print % (a->max))]);
//         print ++;
//     }
// }


int main()
{
    // initialise queue
    struct queue *a;
    printf("How big do you want your queue to be?\n");
    scanf("%d", &a->max);
    (a->data) = malloc((a->max) * sizeof(int));
    a->start = 0;
    a->n = 0;
    printf("enter upto 3 terms you want to push to the queue.\n");
    pushQueue(a);
    pushQueue(a);
    pushQueue(a);

    printf("%d\n",popQueue(a));

    pushQueue(a);

    printQueue(a);
    printArray((a->data), (a->max));
}
