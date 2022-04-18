#include<stdio.h>

char * switch_case(char *n)
{
    int i;
    for(i=0; n[i]!='\0'; i++)
    {
        if (n[i] < 91)
            n[i] = n[i] + 32;
        else if(n[i] > 91)
            n[i] = n[i] -32;
    }
    return n;
}

int main()
{
    char name[20]="WelComErerLUR";
    char *n;
    printf("%s\n", name);
    n = switch_case(name);
    printf("%s", n);
    return 0;
}