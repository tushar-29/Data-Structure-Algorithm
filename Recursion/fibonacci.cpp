#include<stdio.h>
#include<stdlib.h>

int A[10];

// Time comp.=order(2 power n) & Space comp.=order(2 power n)
int fibo_recc(int pos)
{
    if (pos <= 1)
        return pos;
    return (fibo_recc(pos - 2) + fibo_recc(pos - 1));
}

// Time comp.=order(n) & Space comp.=order(1)
int fibo_iter(int pos)
{
    int f1=0, f2=1, sum;
    if(pos <= 1)
        return pos;
    for(int i=2; i<=pos; i++)
    {
        sum= f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum;
}

// Time comp. = order(n) and Space comp.= order(n)
int fibo_memo(int pos)
{
    if (pos <= 1)
    {
        A[pos] = pos;
        return A[pos];
    }
    else
    {
        if (A[pos - 2] == -1)
            A[pos-2] = fibo_memo(pos - 2);

        if (A[pos - 1]== -1)
            A[pos-1] = fibo_memo(pos -1);

        return (A[pos-2] + A[pos-1]);
    }
}


int main()
{
    int i=5;
    // A = (int *)malloc(20 * sizeof(int));
    for(int j=0; j<20; j++)
        A[j]= -1;
    printf("The ith term of fibonacci series using reccursion = %d\n", fibo_recc(i));
    printf("The ith term of fibonacci series using iteration = %d\n", fibo_iter(i));
    printf("The ith term of fibonacci using memoniation = %d\n", fibo_memo(i));
    return 0;
}
