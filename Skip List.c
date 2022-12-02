#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

// skip list implementation

struct node {
    int data;
    int num;
    int * *next; //create a list of addresses
}*root;

int skipListRandGen()
{
    int thing;
    int counter = 1;

    while (thing != 0)
    {
        thing = rand()%2;
        counter += thing;
        if (thing == 0)
        {
            break;
        }
    }
    return counter;
}

struct node *createSkipList(int *a, int n)
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head -> data = a[0];
    head -> num = skipListRandGen();
    head -> next = (int **)malloc((head -> num) * sizeof(int *));

    for (int i = 0; i < (head -> num); i++)
    {
        (head -> next)[i] = NULL;
    }



    for (int i = 0; i < n; i++)
    {
        
    }
}

void SkipListDelete(int *head, int a)
{
    // check head n size. see what the largest jump you want to be is and track it
}




int main()
{
    int n;
    int *a; 
    struct node *head;
    srand(time(0));


    printf("Please enter the size of your array n \n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements as space separated integers: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
