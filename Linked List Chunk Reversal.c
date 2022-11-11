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

struct node *reverseList(struct node *head) // function to reverse a linked list without creating a new linked list
{
    struct node *prev = NULL; // prev is set to NULL to denote end of linked list
    struct node *newNode = head; // temp is set to head
    struct node *temp = head -> next; 

    while (temp!= NULL)
    {
        newNode->next = prev; // temp points to term before temp

        prev = newNode; // as we move to the next term, temp becomes prev
        newNode = temp; // temp becomes next term 
        temp = temp->next; // moves to next term
    }
    newNode->next = prev;
    return newNode;
}

struct node *creverseList(struct node *head)
{
    int rev;
    scanf("%d", &rev);

    struct node *prev = NULL; // prev is set to NULL to denote end of linked list
    struct node *newNode = head; // temp is set to head
    struct node *temp = head -> next;
    struct node *headtracker = head;
    int i;

    while (temp!= NULL) 
    {
        for (i = 0; i++;)
        {
            if (i % (2 * rev) < rev)
            {
                newNode->next = prev; // temp points to term before temp

                prev = newNode; // as we move to the next term, temp becomes prev
                newNode = temp; // temp becomes next term 
                temp = temp->next; // moves to next term
            }
            if (i % (2 * rev) == rev)
            {
                prev = headtracker;
                newNode = temp;
                headtracker->next = newNode;
                temp = temp->next;
            }
            if (i % (2 * rev) > rev)
            {
                prev = newNode;
                newNode = temp;
                headtracker = headtracker->next;
                temp = temp->next;
            }
        }
    }
    return newNode;

}



// count each linked list term

// do things to each node based on what it is % 2n

// i % 2n = 0 - head value, save
// i % 2n < n -- reverse
// i % 2n = n - head directs to this
// i % 2n = (2n-1) - end of normal list directs to this 

// 0 1 2 3 4 5 6 7 8 9 10 11
// 1 0 2 3 5 4 6 7 9 8 10 11 (2)
// 2 1 0 3 4 5 8 7 6 9 10 11 (3)
// (n-1) ... 2 1 0 | n (n+1) (n+2) ... (2n-1) |||||| (3n-1) ... (2n+2) (2n+1) 2n ||||| 3n (3n + 1) (3n + 2) ... (4n-1)  (n)
// 3 2 1 0 4 5 6 7 11 10 9 8 (4)
// 5 4 3 2 1 0 6 7 8 9 10 11 (6)



// (n-1) <- (2n-1)
// 0  to (n-1) must be reversed
// 0 -> n
// n to (2n-1) must be normal

struct node* chunkrevList(struct node *head)
{
    int n = 0;

    struct node *temp = head;
    while (temp != NULL)
    {   
        temp = temp->next;
        n++;
    }


    struct node *save = NULL;
    struct node *newNode = head;
    temp = head->next;
    struct node *prev = NULL;
    int i, chunk;


    scanf("%d", &chunk);

    for (i = 0; i < n; i++)
    {
        if (i == (n -1))
        {
            head = newNode;
        }
        if (i % (2 * chunk) == 0)
        {
            save = newNode;
        }
        if (i % (2 * chunk) == chunk)
        {
            save->next = newNode;
        }
        if (i % (2 * chunk) < chunk)
        {
            newNode->next = prev;
            prev = newNode;
            newNode = temp;
            temp = temp->next;
        }
        if (i % (2 * chunk) >= chunk)
        {
            prev = newNode;
            newNode = temp;
            temp = temp->next;
        }
        if (i % (2 * chunk) == (n-1))
        {
            save = newNode; 
        }
        if (i % (2 * chunk) == ((2*n)-1))
        {
            newNode->next = save;
        }
    }
    return head;
}

int main()
{
    struct node *head;
    head = createList();
    head = chunkrevList(head);
    traverseList(head);
    return 0;
}

