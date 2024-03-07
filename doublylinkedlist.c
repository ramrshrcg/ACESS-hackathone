#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *newptr, *ptr, *head = NULL;

struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &np->info);

    np->next = NULL;
    np->prev = NULL;
    return np;
}

void create()
{
    struct node *last = NULL;
    char ch;
    do
    {
        newptr = getnode();
        if (head == NULL)
        {
            head = newptr;
        }
        else
        {
            last->next = newptr;
            newptr->prev = last;
        }
        last = newptr;
        printf("Do you want to add more..(y/n)");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void display()
{
    ptr = head;
    printf("The data are: ");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
}
void insertatfront()
{
    newptr = getnode();
    newptr->next = head;
    head->prev = newptr;
    head = newptr;
}
void insertlast()
{
    newptr = getnode();
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newptr;
    newptr->prev = ptr;
}

void insertanywhere()
{
    newptr = getnode();
    int key;
    printf("Enter the key value: ");
    scanf("%d", &key);
    ptr = head;
    while (ptr != NULL && ptr->info != key)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
        printf("key doesnot found\n");
    else
    {
        newptr->next = ptr->next;
        ptr->next = newptr;
        ptr->next->prev = newptr;
        newptr->prev = ptr;
    }
}
void deleteatfront()
{
    if (head == NULL)
        printf("the linked list is empty \n");
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
        head->prev = NULL;
    }
}
void deleteatlast()
{
    if (head == NULL)
        printf("the linked list is empty \n");
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        (ptr->prev)->next = NULL;
        free(ptr);
    }
}
void deleteatanywhere()
{
    if (head == NULL)
        printf("the linked list is empty \n");
    else
    {
        ptr = head;
        int key;
        printf("enter the key value to delette:");
        scanf("%d", &key);

        while (ptr->info != key && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr = NULL)
            printf("key not found\n");
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
}

int main()
{
    int choice, choice2;
    create();
    while (1)
    {
        system("cls");
        printf("Linked List\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Where do you want to enter.\n1. Front\n2. End\n3. Anywhere: ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                insertatfront();
                break;
            case 2:
                insertlast();
                break;
            case 3:
                insertanywhere();
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
            break;
        case 2:
            printf("Where do you want to delete.\n1. Front\n2. End\n3. Anywhere: ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                deleteatfront();
                break;
            case 2:
                deleteatlast();
                break;
            case 3:
                deleteatanywhere();
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
            break;
        case 3:
            display();
            break;
        case 4:

            exit(0);
            break;
        }
        getch();
    }

    return 0;
}
