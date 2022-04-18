#include<stdio.h>

// Tail Recursion can be written in loop in main functing so Space Comp. = order(1) if loop is used
// Space Comp. = order(n),  Time Comp. = order(n)

// Function print the value then call the again
void tail_recc(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x += 10;    // x increase constantly without going into calling process
        printf("%d\t", n + x); 
        tail_recc(n-1);
    }
}

// Function is called till end and then print after comming back from end in reverse 
void head_recc(int n)
{
    static int x =0;
    if (n > 0)
    {
        x += 10;
        head_recc(n-1);
        printf("%d\t", n + x);
    }
}

void tree_recc(int n)
{
    if(n>0)
    {
        printf("%d\t", n);
        tree_recc(n-1);
        tree_recc(n-1);
        printf("\n");
    }
}

int main()
{
    int i = 5;
    tail_recc(i);
    printf("\n");
    head_recc(i);
    printf("\n");
    tree_recc(3);
}
