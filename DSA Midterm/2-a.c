#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// create node data structure
struct node {
    int data;
    struct node *next;
    struct node *next2;
}*head;

struct node *arrayToLLWithNext2(int *a, int n)
{
    struct node *newNode, *temp, *temp2;
    int data;

    if (n <= 0) 
    {
        printf("Bitch");
        exit(0);
    }

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }

    data = a[0];
    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL
    head->next2 = NULL; //


    temp = head;
    temp2 = NULL;
    for(int i = 1; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        data = a[i];

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 
        newNode->next2 = NULL // Make sure new node points to NULL

        if (temp2 != NULL)
        {
            temp2->next2 = newNode;
        }
        temp2 = temp;
        
        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node

    }
    return head;
}

void traverseList(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;
    int *a;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements as space separated integers: \n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    head = arrayToLLWithNext2(a, n);
    traverseList(head);
}