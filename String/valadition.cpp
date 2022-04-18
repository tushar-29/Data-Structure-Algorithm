#include<stdio.h>

int valid(char *name)
{
    int i;
    for(i=0; name[i] != '\0'; i++)
    {
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<= 56))
            return 0;
    }
    return 1;
}

int main()
{
    char name[20]="Tushar24Prasad";
    if(valid(name))
        printf("String is valid\n");
    else
        printf("invalid string\n");
    return 0;    
}
