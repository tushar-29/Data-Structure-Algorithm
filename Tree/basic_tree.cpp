#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Tree *data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

int isFull_st()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp)
        return 0;
    return 1; 
}

int isEmpty_st(struct Stack *st)
{
    if(st->top)
        return 0;
    return 1;
}

void push(struct Stack *st, struct Tree *x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(!isFull_st())
    {
        temp->data = x;
        temp->next = st->top;
        st->top = temp;
    }   
    else
        printf("Stack Overflow\n");
}

struct Tree * pop(struct Stack *st)
{
    struct Node *p = st->top;
    struct Tree *x={NULL};
    if(!isEmpty_st(st))
    {
        x = st->top->data;
        st->top = st->top->next;
        free(p);
    }
    else 
        printf("Stack Underflow\n");
    return x;
}


struct Queue 
{
    struct Node *front, *rear;
};

int isFull()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp)
        return 0;
    return 1;
}

int isEmpty(struct Queue *q)
{
    if(q->front)
        return 0;
    return 1;
}

struct Tree * queueTop(struct Queue *q)
{
    if(!isEmpty(q))
        return q->front->data;
    return NULL;
}

void enqueue(struct Queue *q, struct Tree *x)
{
    if(!isFull())
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = NULL;
        if(q->front == NULL)
            q->front = q->rear = temp;
        else
        {
            q->rear->next = temp;
            q->rear = q->rear->next;
        }    
    }
    else
        printf("Queue overflow\n");
}

struct Tree * dequeue(struct Queue *q)
{
    struct Tree *x = NULL;
    if(!isEmpty(q))
    {
        struct Node *temp = q->front;
        q->front = q->front->next;
        x = temp->data;
        free(temp);
    }
    else
        printf("Queue underflow\n");
    return x;
}


struct Tree
{
    struct Tree *Rchild, *Lchild;
    int data;
};

void creat_tree(struct Tree **root)
{
    struct Queue q;
    q.front = NULL;
    q.rear = NULL;
    int k=0;
    struct Tree *temp , *p;
    temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->Lchild = temp->Rchild = NULL;
    printf("Enter the root element = ");
    scanf("%d", &temp->data);
    *root = temp;
    enqueue(&q, *root);
    while(!isEmpty(&q))
    {
        p = dequeue(&q);
        printf("Enter the Left Child of element %d = ", p->data);
        scanf("%d", &k);
        if(k != -1)
            {
                temp = (struct Tree *)malloc(sizeof(struct Tree));
                temp->Lchild = temp->Rchild = NULL;
                temp->data = k;
                p->Lchild = temp;
                enqueue(&q, temp);
            }
        printf("Enter the Right Child  of Elemet %d = ", p->data);
        scanf("%d", &k);
        if(k != -1)
            {
                temp = (struct Tree *)malloc(sizeof(struct Tree));
                temp->Lchild = temp->Rchild = NULL;
                temp->data = k;
                p->Rchild = temp;
                enqueue(&q, temp);
            }
    }   
}

// Time comp = n+n+1 = 2n+1 = order(n)
void preorder_recc(struct Tree *p)
{
    if(p)
    {
        printf("%d\t", p->data);
        preorder_recc(p->Lchild);
        preorder_recc(p->Rchild);
    }
}

// Time comp = n+n+1 = 2n+1 = order(n)
void inorder_recc(struct Tree *p)
{
    if(p)
    {
        inorder_recc(p->Lchild);
        printf("%d\t", p->data);
        inorder_recc(p->Rchild);
    }
}

// Time comp = n+n+1 = 2n+1 = order(n)
void postorder_recc(struct Tree *p)
{
    if(p)
    {
        postorder_recc(p->Lchild);
        postorder_recc(p->Rchild);
        printf("%d\t", p->data);
    }
}

void preorder_iter(struct Tree *p)
{
    struct Stack t;
    t.top = NULL;
    while (p || !isEmpty_st(&t))
    {
        if(p)
        {
            printf("%d\t", p->data);
            push(&t, p);
            p = p->Lchild;
        }
        else
        {
            p = pop(&t);
            p = p->Rchild;
        }
    }
}

void inorder_iter(struct Tree *p)
{
    struct Stack t;
    t.top = NULL;
    while (p || !isEmpty_st(&t))
    {
        if(p)
        {
            push(&t, p);
            p = p->Lchild;
        }
        else
        {
            p = pop(&t);
            printf("%d\t", p->data);
            p = p->Rchild;
        }
    }
}

void postorder_iter(struct Tree *p)
{
    struct Stack t;
    struct Tree *temp;
    t.top = NULL;
    while (p || !isEmpty_st(&t))
    {
        if(p)
        {
            push(&t, p);
            p = p->Lchild;
        }
        else
        {
            temp = pop(&t);
            if(temp->data > 0)
            {
                temp->data = temp->data * -1;
                push(&t, temp);
                p = temp->Rchild;
            }
            else
            {
                temp->data = temp->data * -1;
                printf("%d\t", temp->data);
                p = NULL;
            }
        }
    }
}

void level_order(struct Tree *p)
{
    struct Queue q;
    q.rear = NULL;
    q.front = NULL;
    printf("%d\t", p->data);
    enqueue(&q, p);
    while(!isEmpty(&q))
    {
        p = dequeue(&q);
        if(p->Lchild)
        {
            printf("%d\t", p->Lchild->data);
            enqueue(&q, p->Lchild);
        }
        if(p->Rchild)
        {
            printf("%d\t", p->Rchild->data);
            enqueue(&q, p->Rchild);
        }
    }
}

int node_count(struct Tree *p)
{
    int x=0, y=0;
    if(p)
    {
        x = node_count(p->Lchild);
        y = node_count(p->Rchild);
        return x + y + 1;
    }
    else    
        return 0;
}

int non_leaf_count(struct Tree *p)
{
    int x=0, y=0;
    if(p)
    {
        x = non_leaf_count(p->Lchild);
        y = non_leaf_count(p->Rchild);
        if(p->Lchild && p->Rchild)
            return x + y + 1;
        return x+y;
    }
    else    
        return 0;
}

int leaf_count(struct Tree *p)
{
    int x=0, y=0;
    if(p)
    {
        x = leaf_count(p->Lchild);
        y = leaf_count(p->Rchild);
        if(!p->Lchild && !p->Rchild)
            return x + y + 1;
        return x+y;
    }
    else    
        return 0;
}

int height(struct Tree *p)
{
    int x=0, y=0;
    if(p)
    {
        x = height(p->Lchild);
        y = height(p->Rchild);
        if(x > y)
            return x+1;
        else    
            return y+1;
    }
    else
        return 0;
}


int main()
{
    struct Tree *root={NULL};
    creat_tree(&root);
    printf("\nPreorder :\t");
    preorder_recc(root);
    printf("\nInorder:\t");
    inorder_recc(root);
    printf("\nPostorder :\t");
    postorder_recc(root);
    printf("\npreorder :\t");
    preorder_iter(root);
    printf("\nInorder :\t");
    inorder_iter(root);
    printf("\nPostorder:\t");
    postorder_iter(root);
    printf("\nLevel Order :\t");
    level_order(root);
    printf("\n no. of node = %d", node_count(root));
    printf("\n no. of non leaf node = %d", non_leaf_count(root));
    printf("\n no. of leaf node = %d", leaf_count(root));
    printf("\n Height of tree = %d", height(root));
    return 0;
}
