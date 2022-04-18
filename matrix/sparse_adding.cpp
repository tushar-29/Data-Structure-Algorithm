#include<stdio.h>
#include<stdlib.h>

struct Element
{
    int num, i, j;
};

struct Sparse 
{
    int m, n, size;
    struct Element *e;
};

void initialize(struct Sparse *st, int row, int col, int elements)
{
    st->m = row;
    st->n = col;
    st->size = elements;
    st->e = (struct Element *)malloc(st->size * sizeof(struct Element));
}

void set(struct Sparse *s, int row, int col, int x, int *flag)
{
    if(*flag<= s->size && x != 0)
    {
        s->e[*flag].i = row;
        s->e[*flag].j = col;
        s->e[*flag].num = x;
        *flag += 1;
    }
}

void display(struct Sparse s)
{
    printf("Sparse array is :\n");
    int x, y, z=0;
    for(x=0; x<s.m; x++)
    {
        for(y=0; y<s.n; y++)
        {
            if(x == s.e[z].i && y == s.e[z].j)
                printf("%d\t", s.e[z++].num);
            else
                printf("0\t");
        }
        printf("\n");
    }
}

struct Sparse * add(struct Sparse s1, struct Sparse s2)
{
    if(!(s1.m == s2.m && s1.n == s2.n))
        return nullptr;
        
    struct Sparse *s3;
    initialize(s3, s1.m, s2.n, s1.size+s2.size);

    int x=0, y=0, z=0;
    while(x<s1.size && y<s2.size)
    {
        if(s1.e[x].i < s2.e[y].i)
            s3->e[z++] = s1.e[x++];

        else if(s1.e[x].i > s2.e[y].i)
            s3->e[z++] = s2.e[y++];

        else
        {
            if(s1.e[x].j < s2.e[y].j)
                s3->e[z++] = s1.e[x++];

            else if(s1.e[x].j > s2.e[y].j)
                s3->e[z++] = s2.e[y++];

            else
            {
                s3->e[z] = s1.e[x++];
                s3->e[z++].num += s2.e[y++].num;
            }
        }
    }
    for(; x<=s1.size; x++)
        s3->e[z++] = s1.e[x];

    for(; y<= s2.size; y++)
        s3->e[z++] = s2.e[y];
    
    s3->size = z;
    return s3;
}

int main()         
{
    int a[4][5]={   {0, 0, 7, 0, 0},
                    {2, 0, 0, 5, 0},
                    {9, 0, 0, 5, 0},
                    {0, 0, 0, 0, 4},
                };

    int b[4][5]={   {0, 0, 0, 9, 0},
                    {0, 0, 4, 0, 0},
                    {9, 0, 0, 0, 8},
                    {2, 0, 0, 0, 0}
                };

// 5 non zero elemets spare s1
    struct Sparse s1;
    initialize(&s1, 4, 5, 5);

    int i, j, flag=0;
    for(i=0; i<s1.m; i++)
    {
        for(j=0; j<s1.n; j++)
                set(&s1, i, j, a[i][j], &flag);
    }
    display(s1);

    // spare matrix 2
    struct Sparse s2;
    initialize(&s2, 4, 5, 4);

    flag =0;
    for(i=0; i<s2.m; i++)
    {
        for(j=0; j<s2.n; j++)
            set(&s2, i, j, b[i][j], &flag);
    }
    display(s2);

    struct Sparse *s3;
    s3 = add(s1, s2);
    display(*s3);
    return 0;
}