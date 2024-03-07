#include <stdio.h>
int main()
{
    int size = 7;
    char ch;
    int ui = 0, li = 0, i, a[size];
    printf("Enter the data in lsit:");
    for (i = 0; i <= size - 1; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
        printf("\n do you want to enter again y\n:");
        scanf(" %c", &ch);
        ui++;
        if (ch != 'y')
            break;
    }
   display: printf("the data are:");
    for (i = li; i <= ui - 1; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
    // insert at front
    printf("insert at front /n");
    {
        if (ui == size - 1)
            printf("sixe is full\n");
        else
        {
            for(i=ui;i>=li;i--)
            {
               a[i+1]=a[i]; 
            }
            printf("value at front  /n");
            scanf("%d",&a[0]);
        }
    }
    int opt;
    printf("check display:1/0");
    scanf("%d",&opt);

    if(opt==1)
   { goto display;}
}