#include <stdio.h>
void TOH(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("move disk 1 from %c to %c\n", source, destination);
    }
    else
    {
        TOH(n - 1, source, auxiliary, destination);
        printf("move %d from %c to %c\n", n, source, destination);
        TOH(n - 1, auxiliary, destination, source);
    }
}
int main()
{
    int n = 5;
    char source = 'S';
    char destination = 'D';
    char auxiliary = 'A';
    TOH(n, source, destination, auxiliary);

    return 0;
}