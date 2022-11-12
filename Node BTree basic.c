// quicksort
// chunk reversal
// heapsort
 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
}*root;

struct node *createBTree()
{
    int n;
    scanf("%d", &n);

    int data;
    scanf("%d", &data);

    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = NULL;
    t->right = NULL;

    for (int i = 1; i < n; i++)
    {
        scanf("%d", data);
        struct node *temp = t;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = (struct node *)malloc(sizeof(struct node));
                    temp->left->data = data;
                    temp->left->left = NULL;
                    temp->left->right = NULL;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = (struct node *)malloc(sizeof(struct node));
                    temp->right->data = data;
                    temp->right->left = NULL;
                    temp->right->right = NULL;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }


    return t;
}



void traverseBTree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    traverseBTree(root->left);
    traverseBTree(root->right);
    printf("\n");
}

int main()
{
    struct node *root = createBTree();
    traverseBTree(root);
    return 0;
}s
