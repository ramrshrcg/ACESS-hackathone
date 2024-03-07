#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *newptr, *head = NULL, *ptr;

struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &np->info);
    printf("The linked list is created.\n");
    np->next = NULL;
    return np;
}

void create()
{
    struct node *last;
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
        }
        last = newptr;

        printf("enter character y/n: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void display()
{
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

void insreratfront()
{
    display();
    newptr = getnode();
    newptr->next = head;
    head = newptr;
    display();
}

void insertatend()
{
    display();
    ptr = head;
    newptr = getnode();
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newptr;
    display();
}

void insertatanywhere()
{
    int key;
    display();
    printf("\nWhere do you want to enter. The data will be added after the key value. Enter the key value: ");
    scanf("%d", &key);
    newptr = getnode();
    ptr = head;

    while (ptr != NULL && ptr->info != key)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("key not found.\n");
    }
    else
    {
        newptr->next = ptr->next;
        ptr->next = newptr;
    }
}

void deleteatanywhere()
{
    int key;
    struct node *temp;
    display();
    printf("\nWhere do you want to delete. The key value wioll be  deleted.  Enter the key value: ");
    scanf("%d", &key);
    ptr = head;
    temp = NULL;

    while (ptr != NULL && ptr->info != key)
    {
        temp = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Key not found.\n");
    }
    else
    {
        if (temp == NULL)
        {
            // Deleting the first node
            head = ptr->next;
        }
        else
        {
            temp->next = ptr->next;
        }
        free(ptr);
        display();
    }
}
void deleteatend()
{
    struct node *temp;
    display();
    ptr = head;
    temp = NULL;

    while (ptr->next != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
    }

    if (temp == NULL)
    {
        // Deleting the only node
        head = NULL;
    }
    else
    {
        temp->next = NULL;
    }
    free(ptr);
    display();
}

void deleteatfront()
{
    display();
    ptr = head;

    if (ptr != NULL)
    {
        head = ptr->next;
        free(ptr);
    }

    display();
}

void freelist()
{
    while (head != NULL)
    {
        ptr = head;
        head = head->next;
        free(ptr);
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
                insreratfront();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatanywhere();
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
                deleteatend();
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
            freelist();
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        getch();
    }

    return 0;
}
