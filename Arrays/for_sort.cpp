#include <stdio.h>

struct Array
{
    int arr[10], length, size;
};

int isSorted(struct Array s)
{
    int i;
    for(i=0; i<s.length-1; i++)
    {
        if(s.arr[i] > s.arr[i+1])
            return 0;
    }
    return 1;
}

void insert(struct Array *s, int num)
{
    if(s->length < s->size)
    {
        int i=s->length-1;
        while (s->arr[i] > num)
        {
            s->arr[i+1] = s->arr[i];
            i--;
        }
        s->arr[i+1] = num;
        s->length++;
    }
} 

void display(struct Array s)
{
    int i;
    printf("Array =");
    for(i=0; i<s.length; i++)
        printf("\t%d", s.arr[i]);
    printf("\n");
}

int main()
{
    int num = 45;
    struct Array s={{10, 20, 30, 40, 50, 60, 70, 80}, 8, 10};
    printf("Is array is sorted? %d\n", isSorted(s));
    display(s);
    insert(&s, num);
    display(s);
    return 0;
}