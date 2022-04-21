/*
Binary Search Tree 
Features : 
 -> No Duplicates
 -> Inorder gives Sorted list
 -> Search time depent upon height of the Tree
 -> For n node  = 2nCn / (n+1) structure are possible (cation no.)

 Time taken for serch in BST is height dependent  so log-n to n so we say Order(log-n)

 */

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

struct Tree * stackTop(struct Stack *st)
{
    if(!isEmpty_st(st))
        return st->top->data;
    return NULL;
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


struct Tree
{
    struct Tree *Lchild, *Rchild;
    int data;
};

int split_element(int *array, int low, int high, int data)
{
    int i=0;
    for(i=low; i<=high; i++)
    {
        if(array[i] == data)
            return i;
    }
    return -1;
}

struct Tree * creat(int *inorder, int *preorder, int low, int high)
{
    static int index = 0;
    if(low > high)
        return NULL;

    struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->data = preorder[index++];
    temp->Lchild = temp->Rchild = NULL;

    if(low == high)
        return temp;
    
    int split_index = split_element(inorder, low, high, temp->data);
    temp->Lchild = creat(inorder, preorder, low, split_index-1);
    temp->Rchild = creat(inorder, preorder, split_index+1, high);
    return temp;
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

void preorder_recc(struct Tree *p)
{
    if(p)
    {
        printf("%d\t", p->data);
        preorder_recc(p->Lchild);
        preorder_recc(p->Rchild);
    }
}

int search_recc(struct Tree *t, int x)
{
    if(!t)
        return 0;
    if(t->data == x)
        return 1;
    if(t->data > x)
        return search_recc(t->Lchild, x);
    else   
        return search_recc(t->Rchild, x);
}

int search_iter(struct Tree *t, int x)
{
    while(t)
    {
        if(t->data == x)
            return 1;
        else if(t->data > x)
            t = t->Lchild;
        else
            t = t->Rchild;
    }
    return 0;
}

void insert(struct Tree *t, int x)
{
    struct Tree *temp=NULL, *tail=NULL;
    while(t)
    {
        tail = t; 
        if(t->data == x)
            return;
        else if(t->data > x)
            t = t->Lchild;
        else
            t = t->Rchild;
    }
    temp = (struct Tree *)malloc(sizeof(struct Tree));
    temp->data = x;
    temp->Lchild = temp->Rchild = NULL;
    if(tail->data > x)
        tail->Lchild = temp;
    else
        tail->Rchild = temp;
}

struct Tree * insert_recc(struct Tree *t, int x)
{
    struct Tree *temp=NULL;
    if(!t)
    {
        temp = (struct Tree *)malloc(sizeof(struct Tree));
        temp->data = x;
        temp->Lchild = t->Rchild = NULL;
        return temp;
    }
    if(t->data > x)
        t->Lchild = insert_recc(t->Lchild, x);
    else
        t->Rchild = insert_recc(t->Rchild, x);
    return t;
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

struct Tree * inorder_pre(struct Tree *p)
{
    while(p && p->Rchild)
        p = p->Rchild;
    return p;
}

struct Tree * inorder_succ(struct Tree *p)
{
    while(p && p->Lchild)
        p = p->Lchild;
    return p;
}

struct Tree * del(struct Tree *t, int x)
{
    if(!t)
        return NULL;
    if(!t->Lchild && !t->Rchild)
    {
        free(t);
        return NULL;
    }

    if(t->data > x)
        t->Lchild = del(t->Lchild, x);
    else if(t->data < x)
        t->Rchild = del(t->Rchild, x);
    else
    {
        struct Tree *temp=NULL;
        if(height(t->Lchild) > height(t->Rchild))
        {
            temp = inorder_pre(t->Lchild);
            t->data = temp->data;
            t->Lchild= del(t->Lchild, temp->data);
        }
        else
        {
            temp = inorder_succ(t->Rchild);
            t->data = temp->data;
            t->Rchild = del(t->Rchild, temp->data);
        }
    }
    return t;
}

void generate_tree(struct Tree **root, int *arr, int n)
{
    struct Stack st;
    st.top = NULL;
    struct Tree *p=NULL, *temp=NULL;
    int i=0;
   *root = (struct Tree *)malloc(sizeof(struct Tree));
    (**root).data = arr[i++];
    (**root).Lchild = (**root).Rchild = NULL;
    p = *root;
    while(i<n)
    {
        if(arr[i] < p->data)
        {
            temp = (struct Tree *)malloc(sizeof(struct Tree));
            temp->data = arr[i++];
            temp->Lchild = temp->Rchild = NULL;
            p->Lchild = temp;
            push(&st, p);
            p = temp;
        }
        else
        {
            int check_data = stackTop(&st) ? stackTop(&st)->data : INT_MAX;
            if(arr[i] > p->data && arr[i] < check_data)
            {
                temp = (struct Tree *)malloc(sizeof(struct Tree));
                temp->data = arr[i++];
                temp->Lchild = temp->Rchild = NULL;
                p->Rchild = temp;
                p = temp;
            }
            else
                p = pop(&st);
        }
    }
}


int main()
{
    int inorder[]={5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};
    int preorder[]={40, 20, 10, 5, 15, 30, 25, 35, 60, 50, 45, 55, 70, 65, 75};
    struct Tree *root={NULL};
    // root = creat(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    generate_tree(&root, preorder, sizeof(preorder)/ sizeof(preorder[0]));
    printf("\nInorder =\t");
    inorder_recc(root);
    printf("\nPreorder :\t");
    preorder_recc(root);

    // root = del(root, 40);
    // printf("\nInorder =\t");
    // inorder_recc(root);    
    // printf("\nPreorder :\t");
    // preorder_recc(root);
    return 0;
}