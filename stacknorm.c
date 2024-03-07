// NOrmal not using a pointer 

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define size 5
struct stack
{
    int top;
    int data[size];

} s;
void push()
{
    if (s.top == size - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        (s.top)++;
        printf("Enter the data to push in the stack");
        scanf("%d", &s.data[s.top]);
        printf("\nData is sucessfully pushed ");
    }
}
void Display()
{
    int i;
    if (s.top == -1)
    {
        printf("stack is empty ");
    }
    else
    {
        printf("The data in the stack are\n");
        for (int i = s.top; i >= 0; i--)
        {
            printf("%d \n", s.data[i]);
        }
    }
}
void pop(){
    if (s.top==-1)
    {
        printf("Stack is empty\n");
    }else{
        printf("Data is popped = %d ",s.data[s.top]);
        (s.top)--;

    }
    

}

int main()
{
   
    int choice;
    s.top = -1;

    while (1)
    {
        //system("cls");
        printf("Choose the number \n 1. Push \n 2. Pop \n 3. Display \n 4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2: pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        }
        getch();
    }
    return 0;
}