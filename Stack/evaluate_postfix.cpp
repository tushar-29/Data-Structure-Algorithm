#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
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

void push(int x)
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
    return -1;
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

int calculator(int x, int y, char opt)
{
    switch(opt)
    {
        case '+': 
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
        default:
            return -1;
    }
}

int evaluate(char *postfix)
{
    int i=0, temp=0, num1, num2;
    for(i=0; i<postfix[i]!='\0'; i++)
    {
        if(isOperator(postfix[i]))
        {
            num2 = pop();
            num1 = pop();
            temp = calculator(num1, num2, postfix[i]);
            push(temp);
        }

        else
            push(postfix[i]-48);
    }
    return pop();
}

int main()
{
    // char expression[] = "3*5+6/2-4", *postexp;
    // printf("%s\n", expression);
    // postexp = convert(expression);
    // printf("%s\n", postexp);
    char postexp[] = "234*+82/-";
    int result=0;
    result = evaluate(postexp);
    printf("Result = %d\n", result);
    return 0;
}