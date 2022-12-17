#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

// avl tree implementation

struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
    struct node *parent;
}*root;

void AVLRR(struct node *a, struct node *b, struct node *c) 
{

    /*
    a                 b
      b        ->   a   c
        c
    */

    b->parent = (a->parent);
    a->parent = b;
    a->right = b->left;
    b->left = a;
}   

void AVLLL(struct node *a, struct node *b, struct node *c)
{
    /*
        c             b
      b        ->   a   c
    a
    */

    b->parent = (c->parent);
    c->parent = b;
    c->left = b->right;
    b->right = c;
}

void AVLRL(struct node *a, struct node *b, struct node *c)
{
    /*
    a               a
      c        ->     b 
    b                   c
    */

    b->parent = a;
    c->parent = b;

    c->left = b->right;
    a->right = b;
    b->right = c;

}

void AVLLR(struct node *a, struct node *b, struct node *c)
{
    /*
      c                 c
    a          ->     b 
      b             a
    */

   a->parent = b;
   b->parent = c;

   a->right = b->left;
   b->left = a;
   c->left = b;
}

void updateAVLTree(struct node *NewNode)
{
    int diff;
    NewNode = NewNode -> parent;

    while (1)
    {
        diff = ((NewNode->left->height) - (NewNode->right->height));
        if ((diff == (-1) ) || (diff == 0) || (diff = 1))
        {
            return;
        }
        if (diff == 2)
        {
            if (NewNode->left->right != NULL)
            {
                AVLLR((NewNode->left), (NewNode->left->right), NewNode);
            }
            AVLLL((NewNode->left->left),(NewNode->left),NewNode);
        }
        if (diff == -2)
        {
            if (NewNode->right->left != NULL) 
            {
                AVLRL(NewNode, (NewNode->right), (NewNode->right->left));
            }
            AVLLL(NewNode, (NewNode->right),(NewNode->right->right));
        }
        
    }
}



struct node *createAVLTree(int a)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));

    head -> data = a;
    head -> height = 0;
    head -> left = NULL;
    head -> right = NULL;
    head -> parent = NULL;
}

void insertAVLTree(int a, struct node* root)
{
    struct node *temp = root;

    while (temp != NULL)
    {
        if (a > (temp -> data))
        {
            temp = temp-> right;
        }
        else
        {
            temp = temp -> left;
        }
    }

    struct node *NewNode = (struct node *)malloc(sizeof(struct node));
    NewNode -> data = a;
    NewNode -> left = NULL;
    NewNode -> right = NULL;
    NewNode -> parent = temp;
    NewNode -> height = 0;
    if (a > (temp -> data))
        {
            temp -> right = NewNode;
        }
        else
        {
            temp -> left = NewNode;
        }
    while (temp != NULL)
    {
        temp->height = (fmax((temp->left->height), (temp->right->height)) + 1);
        temp = temp->parent;
    }

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
    struct node *head;
    srand(time(0));

    int(a);
    scanf("%d", &a);

    head = createAVLTree(a);

    traverseBTree(head);

    scanf("%d", a);

    insertAVLTree(a, head);
}