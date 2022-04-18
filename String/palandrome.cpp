#include<stdio.h>

int ispaladrome(char *name)
{
    int i, j;
    for(j=0; name[j]!='\0'; j++)
    {
    }
    for(i=0, j=j-1; i<j; i++, j--)
    {
        if(name[i] != name[j])
            return 0;
    }
    return 1;
}

int main()
{
    char name[]="madam";
    if(ispaladrome(name))
        printf("It is paladrome\n");
    else
        printf("It's not paladrome\n");
    return 0;
}
