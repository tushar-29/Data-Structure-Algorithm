#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
}*top=NULL;


int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp)
        return 0;
    return 1; 
}

int isEmpty()
{
    if(top)
        return 0;
    return 1;
}

int stackTop()
{
    if(top)
        return top->data;
    return -1;
}

void push(char x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(!isFull())
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }   
    else
        printf("Stack Overflow\n");
}

int pop()
{
    struct node *p=top;
    char x;
    if(!isEmpty())
    {
        top = top->next;
        x = p->data;
        free(p);
        return x;
    }
    else 
        printf("Stack Underflow\n");
    return '\0';
}

int peek(int pos)
{
    if(pos < 0)
        return -1;

    struct node *p=top;
    int i=0;
    for(i=0; i<=pos; i++)
    {
        if(p)
            p = p->next;
        else
            -1;
    }
    return p->data;
}

int check_precidence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return -1;
}

int isOperator(char x)
{
    if(x == '+' || x == '-' || x== '*' || x == '/')
        return 1;
    return 0;
}

char * convert(char *infix)
{
    char *postfix = (char *)malloc(sizeof(infix)+1);
    int i=0, k=0;
    while(infix[i] != '\0')
    {
        if(isOperator(infix[i]))
        {
            if(check_precidence(infix[i]) > check_precidence(stackTop()))
                push(infix[i++]);
            else
                postfix[k++] = pop();
        }
        else    
            postfix[k++] = infix[i++];
    }
    while(!isEmpty())
        postfix[k++] = pop();

    postfix[k] = '\0';
    return postfix;
}

int main()
{
    char expression[] = "a+b-c*d/e*g+h+i", *postexp;
    printf("%s\n", expression);
    postexp = convert(expression);
    printf("%s\n", postexp);
    return 0;
}