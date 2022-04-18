#include<stdio.h>

struct String
{
    char n[20];
    int length;
};

int len(char *n)
{
    int i;
    for(i=0; n[i]!='\0'; i++)
    {}
    return i;
}

// Time comp = order(n*n) or Bigo(n*n)
void duplicate(struct String s)
{
    int i, j, count=0;
    for(i=0; i<s.length; i++)
    {
        count=1;
        if(s.n[i] != '-')
        {
            for(j=i+1; j<s.length; j++)
            {
                if(s.n[i] == s.n[j])
                {
                    count++;
                    s.n[j]='-';
                }
            }
            if(count > 1)
                printf("%c has repated %d times\n", s.n[i], count);
        }
    }
}

void hash_finding(struct String s)
{
    int h[26]={0}, i;
    for(i=0; i<s.length; i++)
    {
        if(s.n[i]>=65 && s.n[i]<=97)
            h[(s.n[i] - 65)]++;
        else 
            h[(s.n[i] - 97)]++;
    }
    for(i=0; i<26; i++)
    {
        if(h[i]> 1)
            printf("%c has occure %d times\n", i+97, h[i]);
    }
}

// Using bit-wise operation to find the duplicate
void find_bit(struct String s)
{
    long int h=0, x;
    int i;
    for(i=0; i<s.length; i++)
    {
        x=1;
        x = x << (s.n[i]-97);
        if((x & h) > 0)
            printf("%c is duplicated\n", s.n[i]);
        else
            h= h | x;
    }
}

int main()
{
    struct String s={"findings"};
    s.length = len(s.n);
    duplicate(s);
    hash_finding(s);
    printf("string = %s", s.n);
    printf("\nUsing bit wise operator\n");
    find_bit(s);
}
