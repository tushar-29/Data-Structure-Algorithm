#include<stdio.h>

// time comp = order(n) & space comp = order(n)
int expo_recc(int m, int n)
{
    if(n == 0)
        return 1;
    return expo_recc(m, n-1) * m;
}

// time comp = order(n) & space comp. = order(1)
int expo_iter(int m, int n)
{
    int product=1;
    for(int i=0; i<n; i++)
        product *= m;
    return product;
}

// time comp = order(log n), space comp = order(log n)
int expo_recc_2(int m, int n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return expo_recc_2(m * m, n / 2);
    else
        return expo_recc_2(m * m, (n-1)/2) * m;
}

int main()
{
    int m=5, n=3;
    printf("5 to the power 3 using recursion = %d\n", expo_recc(m, n));
    printf("5 to the power 3 using iteration = %d\n", expo_iter(m, n));
    printf("5 to power 3 using second recursin = %d", expo_recc_2(3, 5));

}
