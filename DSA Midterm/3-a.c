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
    struct node *root, *newNode, *temp, *temp2;
    int data;
    
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

int main()
{
    int *a;
    int n;

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
    prefixPrint(root);
}