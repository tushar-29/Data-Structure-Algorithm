#include <stdio.h>

//time complex = order(n sq.) & space comp = order(n)
double taylor_recc(int x, int n)
{
    static double power=1.0, factorial=1.0;
   double result = 1.0;
    if(n == 0)
        return 1;
    result = taylor_recc(x, n-1.0);
    power *= x;
    factorial *= n; 
    return (result + power / factorial);
}

// time comp. =order(n) & space comp. =order(1)
double taylor_iter(int x, int n)
{
    double power=1.0, factorial=1.0, sum=1.0;
    for(int i=1; i<=n; i++)
    {
        power *= x;
        factorial *= i;
        sum += power / factorial;
    }
    return sum;
}

//time comp.=order(n) & space comp = order(n)
double taylor_horner_recc(int x, int n)
{
    static double result=1;
    if(n == 0)
        return result;
    result = 1 + (x * result / n);
    return taylor_horner_recc(x, n-1);
}

//time comp.= order(n) & space comp. = order(1)
double taylor_horner_iter(int x, int n)
{
    double sum=1.0;
    for(;n>0; n--)
        sum = 1 + x * sum / n;
    return sum;
}   

int main()
{
    int x = 1, n = 10;
    printf("Taylor series answer using reccursion = %lf\n", taylor_recc(x, n));
    printf("Taylor series answer using iteration = %lf\n", taylor_iter(x, n));
    printf("Taylor series answer using Horner's rule = %lf\n", taylor_horner_recc(x, n));
    printf("Taylor series answer using horners rule = %lf", taylor_horner_iter(x, n));
    return 0;
}
