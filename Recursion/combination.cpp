#include<stdio.h>

//Pascal Triangle Formula
int comb_recc(int n, int r)
{
    if(r == 0 || n == r )
        return 1;
    else 
        return (comb_recc(n-1, r-1) + comb_recc(n-1, r));
}

int main()
{
    int n=5, r=3;
    printf("Answer of n C r question by recurssion = %d\n", comb_recc(n, r));
    return 0;
}
