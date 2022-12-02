#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// create node data structure
struct node {
    int data;
    struct node *next;
}*head;


// function to create a linked list by taking size of input n and the first n space separate values
struct node *createList()
{
    int n; // assume n is an integer
    struct node *newNode, *temp;
    int data;

    // take value n
    scanf("%d", &n);

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

    // Input data of node from the user
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    temp = head;
    for(int i = 1; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

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

struct node *swapNodeData(struct node *i, struct node *j)
{
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}


struct node *SelSortLinkedList(struct node *head)
{
    struct node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    for (int i = 0; i < n; i++)
    {
        struct node *min = head;
        struct node *temp = head;
        for (int j = 0; j < n - i - 1; j++)
        {
            temp = temp->next;
            if (temp->data < min->data)
            {
                min = temp;
            }
        }
        swapNodeData(min, head);
        head = head->next;
    }
}




int main()
{
    struct node *head = createList();
    SelSortLinkedList(head);
    traverseList(head);
    return 0;
}
