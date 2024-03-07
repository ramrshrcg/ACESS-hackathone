#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *ptr, *nptr, *prevptr, *nodeptr = NULL;
struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to add in list: \n");
    scanf("%d", &np->info);
    np->next = NULL;
    return np;
}
void create()
{
    struct node *last;
    char ch;
    do
    {
        nptr = getnode();
        if (nodeptr == NULL)
        {
            nodeptr = nptr;
        }
        else
        {
            last->next = nptr;
        }
        nptr->next = nodeptr;
        last = nptr;

        printf("do you want to enter more:Y or N");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void display()
{
    ptr = nodeptr;
    printf("the data in nodes are: ");
    do
    {

        printf("%d\t", ptr->info);
        ptr = ptr->next;
    } while (ptr != nodeptr);
    getch();
}
void insertion()
{
    int key;
    printf("enter the key value u want to enter the data. \n");
    scanf("%d", &key);
    nptr = getnode();
    ptr = nodeptr;
    do
    {
        ptr = ptr->next;
    } while (ptr->info != key && ptr != nodeptr);
    if (ptr->info != key)
        printf("The node with key= %d not found", key);
    else
    {
        nptr->next = ptr->next;
        ptr->next = nptr;
    }
}
void deletion()
{
    int key;
    printf("enter the key value u want to delete the data. \n");
    scanf("%d", &key);

    if (nodeptr == NULL)
    {
        printf("The linklist is emoty\n");
    }
    else
    {
        ptr = nodeptr;
        do
        {
            prevptr = ptr;
            ptr = ptr->next;
        } while ( ptr != nodeptr&&ptr->info != key);
        if (ptr->info != key)
            printf("NODE with key=%d doesnot exist ", key);
        else
        {
            prevptr->next = ptr->next;
            free(ptr);
        }
    }
}
void merge() {}

int main()
{
    int choice, choice2;
    create();
    while (1)
    {
        //system("cls");
        printf("Linked List\n1.Insert\n2.Delete\n3.Display\n4.merge\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            merge();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
