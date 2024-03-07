#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r)
{
    int x, i, j;
    x = arr[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}
void quicksort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main()
{
    int arr[] = {0, 5, 7, 9, 8, 6, 4, 3, 2, 1};
    int i, p, r;
    p = 0;
    r  = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, p, r);

    for (i = 0; i < r; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}