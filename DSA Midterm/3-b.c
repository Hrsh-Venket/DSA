#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>    

// create node data structure
struct node {
    int data;
    struct node *left;
    struct node *right;
}*root;

struct node *arrayToReverseBST(int *a, int n)
{
    struct node *root, *newNode, *temp;
    
    root = (struct node *)malloc(sizeof(struct node));

    root->data = a[0];
    root->left = NULL;
    root->right = NULL;

    for (int i = 1; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = a[i];
        newNode->left = NULL;
        newNode->right = NULL;
        
        temp = root;
        while (temp != NULL)
        {
            if (newNode->data < temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
    }

    return root;
}

void prefixPrint(struct node *root) // recursive printing
{
    printf("%d ", root->data);
    if (root->left != NULL)
    {
        prefixPrint(root->left);
    }
    if (root->right != NULL)
    {
        prefixPrint(root->right);
    }
}

void successorReverseBST(struct node *root, int k)
{ // right side smaller, left side larger
    struct node *temp = root; // temp is supposed to be the node where k is stored
    struct node *rajthedad = root; // dont judge variable names 

    int kstatus = 0;
    
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            kstatus = 1;
            break;
        }
        else if (temp->data > k) 
        {
// consider when rajthedad is set. if it is in a full rightward chain, that is an issue
            rajthedad = temp;
            temp = temp->right;
        }
        else if (temp->data < k)
        {   
            temp = temp->left;
        }
    }

    if (kstatus == 0)
    {
        printf("Debatan Gupta -- Uh I mean Pudding");
        exit(0);
    }

    // figure out successor element

    struct node *succ = NULL;
    if (temp->left != NULL)
    {
        succ = temp->left;
        while (succ != NULL)
        {
            if (temp->right != NULL)
            {
                succ = succ->right;
            }
        }
    }
    else if (temp ->left == NULL)
    {
        succ = rajthedad;
    }
    if (succ == NULL)
    {
        printf("Hamburger");
    }

    printf("%d", succ->data);
    // to find successor, I will make an array in 
}

int main()
{
    int *a;
    int n, x;

    printf("Enter the number of elements in the array you want to check: \n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Asshole");
        exit(0);
    }

    a = (int *)malloc(n * sizeof(int));


    printf("Enter the elements of the array separated by spaces: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    root = arrayToReverseBST(a, n);

    printf("What element should be successorred?? type it mf\n");

    scanf("%d", &x);

    successorReverseBST(root, x);
}