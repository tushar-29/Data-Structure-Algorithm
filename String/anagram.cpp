#include<stdio.h>

int check_anagram(char *s1, char *s2)
{
    int i, h[26]={0};
    for(i=0; s1[i]!='\0'; i++)
        h[s1[i]-97]++;
    for(i=0; s2[i]!='\0'; i++)
        h[s2[i]-97]--;
    for(i=0; i<26; i++)
    {
        if(h[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    char str_1[]="decimal";
    char str_2[]="medical";
    int x = check_anagram(str_1, str_2);
    if(x)
        printf("Yes they are anagram\n");
    else    
        printf("No they are not anagram\n");
    return 0;
}