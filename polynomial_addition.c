#include <stdio.h>
#include <stdlib.h>

struct node
{
    int c, p;
    struct node *next;
};

struct node *createnode(int coeff, int exp)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->c = coeff;
    temp->p = exp;
    return temp;
}

struct node *createPoly()
{
    int n, coeff, exp;
    struct node *new_node, *temp, *head = NULL;
    printf("Enter the no.of terms:");
    scanf("%d", &n);
    while (n != 0)
    {
        printf("Enter the coefficient:");
        scanf("%d", &coeff);
        printf("Enter the power:");
        scanf("%d", &exp);
        new_node = createnode(coeff, exp);
        if (head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
        n--;
    }
    printf("\n");
    return head;
}

struct node *addPoly(struct node *ptr1, struct node *ptr2, struct node *ptr)
{
    ptr = createnode(0, 0);
    while (ptr1->next && ptr2->next)
    {
        if (ptr1->p > ptr2->p)
        {
            ptr->c = ptr1->c;
            ptr->p = ptr1->p;
            ptr1 = ptr1->next;
        }
        else if (ptr1->p < ptr2->p)
        {
            ptr->c = ptr2->c;
            ptr->p = ptr2->p;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr->c = ptr1->c + ptr2->c;
            ptr->p = ptr1->p + ptr2->p;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr->next = createnode(0, 0);
        ptr = ptr->next;
    }

    struct node *ptr_new;
    if (ptr1->next != NULL)
    {
        ptr_new = ptr1;
    }
    if (ptr2->next != NULL)
    {
        ptr_new = ptr2;
    }

    while (ptr_new->next != NULL)
    {
        ptr->c = ptr_new->c;
        ptr->p = ptr_new->p;
        ptr->next = createnode(0, 0);
        ptr = ptr->next;
        ptr_new = ptr_new->next;
    }
    ptr->next = NULL;
    return ptr;
}

struct node *display(struct node *poly)
{
    // temp = head;
    if (poly == NULL)
    {
        printf("Poly not present");
    }
    else
    {
        while (poly != NULL)
        {
            printf(" %d^%d ", poly->c, poly->p);
            poly = poly->next;
        }
    }
}

void main()
{
    struct node *poly1, *poly2, *poly, *poly3;
    printf("For Equation 1:\n");
    poly1 = createPoly();
    printf("For Equation 2:\n");
    poly2 = createPoly();

    poly3 = addPoly(poly1, poly2, poly);
    // printf("success");
    display(poly3);

}