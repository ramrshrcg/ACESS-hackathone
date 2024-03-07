/* This is a program for queue . circular queue  */
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
    q->rear = 0;
}
void enque(queue *q)
{
    if ((q->rear + 1) % size == q->front)
        printf("The queue is full");
    else
    {
        q->rear = ((q->rear + 1) % size);
        printf("Enter the data to add in queue\n");
        scanf("%d", &q->data[q->rear]);
        printf("The data is added to queue");
        printf("%d %d", q->rear, q->front);
    }
}
void deque(queue *q)
{

    if (q->front == q->rear)
    {
        printf("The queue is empty \n");
    }
    else
    {
        printf("The data is dequed: %d\n", q->data[q->front + 1]);
        q->front = ((q->front + 1) % size);
    }
}

void Display(queue *q)
{
    int i;

    if (q->rear == q->front)
        printf(" The queue is empty ");
    else
    {
        if (q->rear > q->front)
        {
            printf("The data in queue are:\n");
            for (i = q->front + 1; i <= q->rear; i++)
            {
                printf("%d\n", q->data[i]);
            }
        }
        else
        {
            for (i = q->front + 1; i < size; i++)
            {
                printf("%d \n", q->data[i]);
            }
            for (i = 0; i <= q->rear; i++)
            {
                printf("%d \n", q->data[i]);
            }
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
