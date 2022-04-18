#include<stdio.h>

//Time Comp. = order(2 to power n) and Space comp. = order(n)
void TOH(int n, char A, char B, char C)
{
    if(n > 0)
        {
            TOH(n-1, A, C, B);
            printf("move %c to %c\n", A, C);
            TOH(n-1, B, A, C);
        }
}

int main()
{
    int i =3;
    TOH(i, 'A', 'B', 'C');
    return 0;
}
