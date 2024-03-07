/* This is a program for queue . without shifting */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5
typedef struct Queue
{
    int data[size];
    int front, rear;

} queue;
void initialization(queue *q)
{
    q->front = 0;
    q->rear = -1;
}
void enque(queue *q)
{
    if (q->rear == size - 1)
        printf("the queue is full");
    else
    {
        q->rear++;
        printf("Enter the data to add in queue\n");
        scanf("%d", &q->data[q->rear]);
        printf("The data is added to queue");
    }
}
void deque(queue *q)
{
    if (q->front > q->rear)
    {
        printf("the queue is empty ");
    }
    else
    {
        printf("The data is dequed: %d\n", q->data[q->front]);
        q->front++;
    }
}

void Display(queue *q)
{
    int i;
  

    if (q->rear < q->front)
        printf(" The queue is empty ");
    else
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d \n", q->data[i]);
            
        }
    }
}

int main()
{

    queue *q = (queue *)malloc(sizeof(queue));
    int choice;
    initialization(q);

    while (1)
    {
        // system("cls");
        printf("Choose the number \n 1. Enque \n 2. Deque \n 3. Display \n 4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enque(q);
            break;
        case 2:
            deque(q);
            break;
        case 3:
            Display(q);
            break;
        case 4:
            exit(0);
        }
        getch();
    }

    free(q);
    return 0;
}
