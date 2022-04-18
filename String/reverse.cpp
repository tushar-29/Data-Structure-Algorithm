#include<stdio.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *name)
{
    int i, temp, j;
    for(j=0; name[j]!='\0'; j++)
    {
    }
    for(i=0, j=j-1; i<j; i++, j--)
        swap(&name[i], &name[j]);
}

int main()
{
    char name[]="python";
    printf("original name = %s\n", name);
    reverse(name);
    printf("reverse string = %s", name);
    return 0;
}