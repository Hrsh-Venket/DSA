#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// create node data structure
struct node {
    int data;
    struct node *next;
    int k;
    struct node *nextk;
}*head;

struct node *arrayToLLWithNextK(int *a, int n)
{
    struct node *newNode, *temp, *temp2, *temp3, *temp4, *temp5;
    int data;

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
    head->nextk = NULL; //
    head->k = ((rand()%4)+2);


    temp = head;
    temp2 = NULL;
    temp3 = NULL;
    temp4 = NULL;
    temp5 = NULL;

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
        newNode->nextk = NULL; // Make sure new node points to NULL
        newNode->k = ((rand()%4)+2);

        if ((temp2 != NULL) && (temp2->k == 2))
        {
            temp2->nextk = newNode;
        }

        if ((temp3 != NULL) && (temp3->k == 3))
        {
            temp3->nextk = newNode;
        }
        
        if ((temp4 != NULL) && (temp4->k == 4))
        {
            temp4->nextk = newNode;
        }

        if ((temp5 != NULL) && (temp5->k == 5))
        {
            temp3->nextk = newNode;
        }

        
        temp2 = temp;
        temp3 = temp2;
        temp4 = temp3;
        temp5 = temp4;
        
        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node

    }
    return head;
}

struct node *reverseLLWithNextK(struct node *head) // function to reverse a linked list without creating a new linked list
{
    struct node *prev5 = NULL;
    struct node *prev4 = NULL;
    struct node *prev3 = NULL;
    struct node *prev2 = NULL;
    struct node *prev = NULL; // prev is set to NULL to denote end of linked list
    struct node *newNode = head; // temp is set to head
    struct node *temp = head -> next; 

    while (temp!= NULL)
    {
        newNode->next = prev; // temp points to term before temp
        if (newNode->k == 2)
        {
            newNode->nextk = prev2;
        }
        if (newNode->k == 3)
        {
            newNode->nextk = prev3;
        }
        if (newNode->k == 4)
        {
            newNode->nextk = prev4;
        }
        if (newNode->k == 5)
        {
            newNode->nextk = prev5;
        }
        



        if (prev4 != NULL)
        {
            prev5 = prev4;
        }
        if (prev3 != NULL)
        {
            prev4 = prev3;
        }
        if (prev2 != NULL)
        {
            prev3 = prev2;
        }
        if (prev != NULL)
        {
            prev2 = prev;
        }
        prev = newNode; // as we move to the next term, temp becomes prev
        newNode = temp; // temp becomes next term 
        temp = temp->next; // moves to next term
    }
    newNode->next = prev;
    if (newNode->k == 2)
    {
        newNode->nextk = prev2;
    }
    if (newNode->k == 3)
    {
        newNode->nextk = prev3;
    }
    if (newNode->k == 4)
    {
        newNode->nextk = prev4;
    }
    if (newNode->k == 5)
    {
        newNode->nextk = prev5;
    }

    return newNode;
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
    if (n <= 0) 
    {
        printf("Bitch");
        exit(0);
    }
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements as space separated integers: \n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    head = arrayToLLWithNextK(a, n);
    head = reverseLLWithNextK(head);
    traverseList(head);
}