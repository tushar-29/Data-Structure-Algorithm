#include<stdio.h>

void permunt(char *str, int k=0)
{
    static int a[5]={0};
    static char set[10];
    int i=0;
    if(str[k] == '\0')
    {
        set[k] = '\0';
        printf("%s\n", set);
    }
    else
    {
        for(i=0; i<str[i]!=0; i++)
        {
            if(a[i] == 0)
            {
                set[k] = str[i];
                a[i] = 1;
                permunt(str, k+1);
                a[i] = 0;
            }
        }
    }
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permuat_swap(char *str, int low, int high)
{
    int i;
    if(low == high)
    {
        printf("%s\n", str);
    }
    else
    {
        for(i=0; i<=high; i++)
        {
            swap(&str[i], &str[low]);
            permuat_swap(str, low+1, high);
            swap(&str[i], &str[low]);
        }
    }
}

int main()
{
    char name[]="ABC";
    permunt(name);
    printf("\n\n");
    permuat_swap(name, 0, 2);
    return 0;
}