#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *arr;
    int size;
};

struct stack
{
    struct Array *a;
    int top;
};


void creat(struct stack *s, int n)
{
    s->a->size= n;
    s->a->arr = (int *)malloc(s->a->size * sizeof(int));
    s->top = -1;
}

int isFull(struct stack *s)
{
    if(s->top+1 == s->a->size)
        return 1;
    return 0;
}

int isEmpty(struct stack *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

void push(struct stack *s, int x)
{
    if(!isFull(s))
        s->a->arr[++s->top] = x; 
    else
        printf("Stack Overflow\n");
}

int pop(struct stack *s)
{
    int x;
    if(!isEmpty(s))
        return  s->a->arr[s->top--];
    else   
        printf("Stack Underflow\n");
    return -1;
}

int peek(struct stack *s, int pos)
{
    if(s->top-pos+1 < 0)
        return -1;
    return s->a->arr[s->top - pos + 1];
}

int stackTop(struct stack *s)
{
    if(!isEmpty(s))
        return s->a->arr[s->top];
    return -1;
}

int main()
{
    int stack_size = 5;
    struct stack *s;
    creat(s, stack_size);
    int i=0;
    for(i=10; i<51; i+=10)
        push(s, i);

    printf("element at pos 2 is = %d\n", peek(s, 2));
    
    for(i=0; i<5; i++)
        printf("%d\t", pop(s));
    return 0;
}
