#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// playing around with pointers

struct node {
    int data;
    struct node *next;
}*head;

int main() 
{
    struct node* head;
    head->next = &head;
    head->data = 5;

    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}