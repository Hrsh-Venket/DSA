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

int deleteNode(struct node *root, struct node *node)
{
    // find the parent of node to be deleted
    struct node *parent = root;
    while (parent != NULL)
    {
        if (parent->left == node || parent->right == node)
        {
            break;
        }
        else if (node->data < parent->data)
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
    }

    // if node has no children, set its parent's pointer to NUll and free node
    if (node->left == NULL && node->right == NULL)
    {
        if (parent->left == node)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(node);
    }
    // if node has one child, set its parents pointer to the child and free node
    else if (node->left == NULL || node->right == NULL)
    {
        struct node *child = node->left == NULL ? node->right : node->left;
        if (parent->left == node)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        free(node);
    }
    // if node has two children, find the inorder successor or predecessor of node, 
    else if (node->left != NULL && node->right != NULL)
    {
        struct node *successor = node->right;
        struct node *successorParent = node;
        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        // if successor is not a direct child of node, set successorParent's left pointer to successor's right child
        if (successorParent != node)
        {
            successorParent->left = successor->right;
        }
        // if successor is a direct child of node, set node's right pointer to successor's right child
        else
        {
            node->right = successor->right;
        }

        // set successor's left and right pointers to node's left and right children
        successor->left = node->left;
        successor->right = node->right;

        // set parent's pointer to successor
        if (parent->left == node)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }

        free(node);
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
    struct node *root = createBTree();
    traverseBTree(root);
    deleteNode(root);
    return 0;
}
