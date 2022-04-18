#include<stdio.h>

int sum_recc(int n)
{
    if (n<=1)
        return n;
    return sum_recc(n-1) + n;
}

int sum_iter(int n)
{
    int sum = 0;
    for(int i=n; i>0; i--)
        sum += i;
    return sum;
    
}

int sum_for(int n)
{
    return (n*(n+1))/2;
}

int main()
{
    int i = 5;
    printf("Sum of n natural number using iteration = %d\n", sum_iter(i));
    printf("Sum of n natural no. with formula = %d\n", sum_for(i));
    printf("Sum of natural no. using recurssion = %d\n", sum_recc(i));
}

// time comp. = order(n) for both 

// space comp. = order(n) for recurssion i.e height of recuressive tree + 1
// space comp. = order(1) for iteration since no. all thing is done in same activation record;
 
 // formula for sum of n natural no. is = n(n+1)/2
 // so time comp. = order(1) and space comp. = order(1)
 