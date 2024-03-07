#include <stdio.h>
#include<stdlib.h>
struct node
{
    float coefficient;
    int exponent;
    struct node *link;
};
struct node *create(struct node *head)
{
    int i, n;
    float coeff;
    int expo;
    printf("enter the no of terms:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the coefficient for term %d", i + 1);
        scanf("%d", &coeff);
        printf("enter the exponent for term %d", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}
struct node *insert(struct node*head,  float coeff, int expo)
{
    struct node *temp;
    struct node* newp = malloc(sizeof(struct node));
    newp->coefficient= coeff;
    newp->exponent= expo;
    newp->link= NULL;

    if (head== NULL|| expo>head->exponent)
    {
        newp->link= head;
        head= newp;
    }else{
        temp = head;
        while(temp->link!=NULL&&temp->link->exponent>=expo)
        temp=temp->link;
        newp->link=temp->link;
        temp->link= newp;
    }return head;
    ds
    


}

