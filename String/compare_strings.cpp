#include<stdio.h>

int strcomp(char *n1, char *n2)
{
    int i, j;
    for(i=0, j=0; n1[i]!='\0' || n2[j]!='\0'; i++, j++)
    {
        if(n1[i] != n2[j])
            return 0;
    }
    return 1;
}

int case_strcomp(char *n1, char *n2)
{
    int i, j;
    for(i=0, j=0; n1[i]!='\0' || n2[j]!='\0'; i++, j++)
    {
        
    }
}

int main()
{
    char name_1[]="Painter";
    char name_2[]="Painteresd";
    if(strcomp(name_1, name_2))
        printf("both are same");
    else    
        printf("Both are different");
}
