#include <stdio.h>

// pass by value
void swap_1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// pass by address
void swap_2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10, b = 20;
    swap_1(a, b);
    printf("a = %d\nb = %d\n", a, b);

    swap_2(&a, &b);
    printf("a = %d\nb = %d", a, b);
}
