#include <stdio.h>

int fact_recc(int n)
{
    if(n<=1)
        return 1;
    return fact_recc(n-1) * n;
}

int fact_iter(int n)
{
    int product = 1;
    for(int i=n; i>1; i--)
        product *= i;
    return product;
}

int main()
{
    int i = 5;
    printf("Factorial of n number using recursion = %d\n", fact_recc(i));
    printf("Factorial of n number using iteration = %d\n", fact_iter(i));
    return 0;
}

// both take Time comp. = order(n)
// recursive take Space Comp. = order(n) whare as iteration take Space Comp. = order(1)
