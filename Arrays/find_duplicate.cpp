#include <stdio.h>

struct Array
{
    int arr[20], length, size;
};

// Time comp = order(n)
void duplicate_sorted(struct Array s)
{
    int i, j;
    if(s.length <= s.size)
    {
        printf("Duplicate element :\n");
        for(i=0; i<s.length-1; i++)
        {
            if(s.arr[i] == s.arr[i+1])
            {
                j=i+1;
                while(s.arr[i] == s.arr[j])
                    j++;
                printf("%d appear %d times\n", s.arr[i], j-i);
                i = j-1;
            }
        }
    }
    printf("\n");
}

//order of (n) or bigo(n)
void duplicated_hash(struct Array s)
{
    int h[12]={0}, i;
    for(i=0; i<s.length; i++)
        h[s.arr[i]]++;

    printf("Missing Element :\n");
    for(i=0; i<12; i++)
    {
        if(h[i] > 1)
            printf("%d appear %d times\n", i, h[i]);
    }
}

// Time comp = order(n*n) or Bigo(n*n)
void duplicated_unsorted(struct Array s)
{
    if(s.length <= s.size && s.length > 1)
    {
        int i, j, count;
        for(i=0; i<s.length; i++)
        {
            count =1;
            if(s.arr[i] != -1)
            {
                for(j=i+1; j<s.length; j++)
                {
                    if(s.arr[j] == s.arr[i])
                    {
                        count++;
                        s.arr[j] = -1;
                    }
                }
                if(count > 1)
                    printf("%d appear %d times\n", s.arr[i], count);
            }
        }
    }
}

// Time Comp. = order(n*n)
void sum_k(struct Array s, int sum)
{
    int i,j;
    if(s.length <= s.size && s.length > 1)
    {
        for(i=0; i<s.length; i++)
        {
            for(j=i+1; j<s.length; j++)
            {
                if(s.arr[i] + s.arr[j] == sum)
                    printf("%d and %d sum is %d\n", s.arr[i], s.arr[j], sum);
            }
        }
    }
}

//order of (n) or bigo(n)
void sum_hash(struct Array s, int sum)
{
    int h[12]={0}, i;
    for(i=0; i<s.length; i++)
    {
        if(h[10 - s.arr[i]] != 0)
            printf("%d and %d give sum %d\n", s.arr[i], 10- s.arr[i], sum);
        h[s.arr[i]]++;
    }
}

// order of bigo(n)
void sum_sorted(struct Array s, int sum)
{
    int i=0, j=s.length-1;
    while(i<j)
    {
        if(s.arr[i] + s.arr[j] > 10)
            j--;
        else if(s.arr[i] + s.arr[j] < 10)
            i++;
        else 
        {
            printf("%d and %d are sum of %d\n", s.arr[i], s.arr[j], sum);
            i++;
            j--;
        }
    }
}

int main()
{
    struct Array s={{1, 5, 6, 6, 7, 8, 9, 9, 9, 9, 10, 11}, 13, 20};
    struct Array s1 = {{10, 11, 2, 7, 6, 2, 11, 5, 11, 4, 3, 11}, 13, 20};
    struct Array s2 = {{2, 7, 3, 9, 4, 5, 6, 8}, 9, 15};
    struct Array s3 = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, 15};
    duplicate_sorted(s);
    duplicated_hash(s);
    duplicated_unsorted(s1);
    duplicated_hash(s1);
    sum_k(s2, 10);
    printf("Using hashing \n");
    sum_hash(s2, 10);
    printf("sorted\n");
    sum_sorted(s3, 10);
    return 0;
}
