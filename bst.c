#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lcptr, *rcptr;
};
struct node *root = NULL, *ptr, *newptr, *parent;
struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &np->data);
    np->lcptr = NULL;
    np->rcptr = NULL;
    return np;
}
void create()
{
    char ch;
    do
    {
        newptr = getnode();
        if (root == NULL)
            root = newptr;
        else
        {
            ptr = root;
            while (ptr != NULL)
            {
                parent = ptr;
                if (newptr->data < ptr->data)
                    ptr = ptr->lcptr;
                else
                    ptr = ptr->rcptr;
            }
            if (newptr->data < parent->data)
                parent->lcptr = newptr;
            else
                parent->rcptr = newptr;
        }
        printf("Do you want to add more(y or n)");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        preorder(ptr->lcptr);
        preorder(ptr->rcptr);
    }
}
struct node *search(int key)
{
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == key)
            return ptr;
        else if (key < ptr->data)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }
    return ptr;
}
void insert()
{
    newptr = getnode();
    ptr = root;
    while (ptr != NULL)
    {
        parent = ptr;
        if (newptr->data < ptr->data)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }
    if (newptr->data < parent->data)
        parent->lcptr = newptr;
    else
        parent->rcptr = newptr;
}
int inorder_aucessor(struct node *root)
{
    while (root->lcptr != NULL)
        root = root->lcptr;
    return root->data;
}
struct node *delette(struct node *ptr, int key)
{
    while (ptr != NULL && ptr->data != key)
    {
        parent = ptr;
        if (key < ptr->data)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }
    if (ptr == NULL)
    {
        printf("NODE EITH KEY DOESNOT EXISTS.\n");
    }
    else if (ptr->lcptr == NULL && ptr->rcptr == NULL) // leaf node
    {

        if (key < parent->data)
            parent->lcptr = NULL;
        else
            parent->rcptr = NULL;
        free(ptr);
    }
    else if (ptr->lcptr == NULL || ptr->rcptr == NULL) // only one child
    {
        if (key<parent->data)
        {
            if (ptr->lcptr== NULL)
            {
                parent->lcptr = ptr->rcptr;
            }
            else
                parent->lcptr = ptr->lcptr;
        }
        else
        {
            if (ptr->lcptr == NULL)
                parent->rcptr = ptr->rcptr;
            else
                parent->rcptr = ptr->lcptr;
        }
    }
    else
    {   
        
        int del_data = inorder_aucessor(ptr->rcptr);
        root = delette(root, del_data);
        ptr->data = del_data;
    }
    return root;
}

int main()
{
    struct node *found;
    int choice;
    int key;
    create();
    while (1)
    {
        // system("cls");
        printf("choose \n1.Insert\n2.Delete\n3.Display\n4.searchinng\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("enter the key to delete: ");
            scanf("%d", &key);

            delette(root, key);
            break;
        case 3:
            preorder(root);
            break;

        case 4:

            printf("entrt the key value to search: ");
            scanf("%d", &key);
            found = search(key);
            if (found == NULL)
                printf("key is not found\n");
            else
                printf("%d is found\n", found->data);

            break;
        }
    }
    return 0;
}