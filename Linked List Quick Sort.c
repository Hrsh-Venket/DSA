#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// create node data structure
struct node {
    struct node *prev;
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

    head->prev = NULL; // Link prev field to NULl
    head->data = data; // Link data field with data
    head->next = NULL; // Link next field to NULL

    temp = head;





    for(int i = 2; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        scanf("%d", &data);


        newNode->prev = temp; // back link newNode
        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node, previous node
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


void QuickSortLinkedList(struct node *i, struct node *j) // figure this out
{
	if (i == j) // if the the input is 1,then do nothing
	{
		return;
	}
    
    // count number of terms
    int n = 0;
    struct node *temp = i;
    while (temp->next != j)
    {
        n++;
        temp = temp->next;
    }


	struct node *pivot;
    if (j == NULL)
    {
        pivot = temp;
    }
    else
    {
        pivot = j;
    }
    
    struct node *high = i;
    struct node *low = j->prev;

    int warn = 0;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
        {
            if (high >= low)
            {
                warn = 1;
                break;
            }
            else if (high->data > pivot->data)
            {
                break;
            }
            else
            {
                high = high->next;
            }
        }
        for (int q = 0; q < n; q++)
        {
            if (high >= low)
            {
                warn = 1;
                break;
            }
            else if (low->data < pivot->data)
            {
                break;
            }
            else
            {
                low = low->prev;
            }
        }
        if (warn == 1)
        {
            break;
        }
        else
        {
            swapNodeData(high, low);
        }
    }

    swapNodeData(pivot, high);
    QuickSortLinkedList(i, low);
    QuickSortLinkedList(high->next, j);
	// take a random number and compare all terms to left and right of that number
	// do this recursively 
}







int main()
{
    struct node *head = createList();
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    QuickSortLinkedList(head, temp);
    traverseList(head);
    return 0;
}
