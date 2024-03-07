/*This is a stack problem , using pointer */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 5
typedef struct Stack
{
    int data[size];
    int top;

} stack;

void initialization(stack *s)
{
    s->top = -1;
}
void push(stack *s)
{
    if (s->top==size-1)
        printf("The stack is full");
    else
    {
        s->top++;
        printf("enter the data");
        scanf("%d", &s->data[s->top]);
        printf("\nThe data is pushed");
    }
}
void pop(stack *s)
{
    if (s->top==-1)
        printf("the stack is empty ");
    else
    {
        printf("The data is popped : %d", s->data[s->top]);
        s->top--;
    }
}
void display(stack *s)
{
    if (s->top==-1)
    {
        printf("The stack is empty and northing to show");
    }
    else
    {
        printf("The data in stack are:\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n",s->data[s->top]);
        }
        
    }
}

int main()
{
    int choice;
    stack *s = (stack *)malloc(sizeof(stack));
    initialization(s);
    while (1)
    {
        system("cls");
        printf("Enter the choice \n1.Push\n2.Pop\n3.Display\n4.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(0);
        }
        getch();
    }
    free(s);//re;easws memory 
    return 0;
}
