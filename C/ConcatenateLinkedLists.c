//CONCATENATE TWO SINGLY LINKED LISTS - C PROGRAM
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * p;
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void concatenate(struct node *a, struct node *b)
{
    if (a != NULL && b != NULL)
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next, b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}

int main()
{
    struct node *prev, *a, *b;
    int n, i;
    printf("number of elements in a:");
    scanf("%d", &n);
    a = NULL;
    for (i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (a == NULL)
            a = p;
        else
            prev->next = p;
        prev = p;
    }
    display(a);
    printf("\n Number of elements in b:");
    scanf("%d", &n);
    b = NULL;
    for (i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (b == NULL)
            b = p;
        else
            prev->next = p;
        prev = p;
    }
    display(b);
    concatenate(a, b);
    printf("\n");
    printf("\nConcatenated singly list elements are: \n");
    display(a);
    getch();
    return 0;
}