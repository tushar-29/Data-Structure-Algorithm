#include<stdio.h>
#include<stdlib.h>

struct Tree
{
    struct Tree *Lchild;
    int data, height;
    struct Tree *Rchild;
};

void inorder_recc(struct Tree *p)
{
    if(p)
    {
        inorder_recc(p->Lchild);
        printf("%d\t", p->data);
        inorder_recc(p->Rchild);
    }
}


void postorder_recc(struct Tree *p)
{
    if(p)
    {
        postorder_recc(p->Lchild);
        postorder_recc(p->Rchild);
        printf("%d\t", p->data);
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

int get_height(struct Tree *t)
{
    int hl, hr;
    hl = t && t->Lchild ? t->Lchild->height : 0;
    hr = t && t->Rchild ? t->Rchild->height : 0;
    return hl > hr ? hl+1 : hr+1;
}

int balance_factor(struct Tree *t)
{
    int hl, hr;
    hl = t && t->Lchild ? t->Lchild->height : 0;
    hr = t && t->Rchild ? t->Rchild->height : 0;

    return hl-hr;
}


struct Tree * LLrotation(struct Tree *t)
{
    struct Tree *Lside = t->Lchild;
    struct Tree *LRside = Lside->Rchild;

    Lside->Rchild = t;
    t->Lchild = LRside;
    t->height = get_height(t);
    Lside->height = get_height(Lside);

    return Lside;
}

struct Tree * LRrotation(struct Tree *t)
{
    struct Tree *Lside = t->Lchild;
    struct Tree *LRside = Lside->Rchild;

    Lside->Rchild = LRside->Lchild;
    LRside->Lchild = Lside;
    t->Lchild = LRside->Rchild;
    LRside->Rchild = t;

    Lside->height = get_height(Lside);
    t->height = get_height(t);
    LRside->height = get_height(LRside);

    return LRside;
}

struct Tree * RLrotation(struct Tree *t)
{
    struct Tree *Rside = t->Rchild;
    struct Tree *RLside = Rside->Lchild;

    Rside->Lchild = RLside->Rchild;
    RLside->Rchild = Rside;
    t->Rchild = RLside->Lchild;
    RLside->Lchild = t;

    Rside->height = get_height(Rside);
    t->height = get_height(t);
    RLside->height = get_height(RLside);

    return RLside;
}

struct Tree * RRrotation(struct Tree *t)
{
    struct Tree *Rside = t->Rchild;
    struct Tree *RLside = Rside->Lchild;

    Rside->Lchild = t;
    t->Rchild = RLside;
    t->height = get_height(t);
    Rside->height = get_height(Rside);

    return Rside;
}

struct Tree * insert(struct Tree *t, int x)
{
    
    if(!t)
    {
        struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
        temp->data = x;
        temp->height = 1;
        temp->Lchild = temp->Rchild = NULL;
        return temp;
    }
    if(t->data > x)
        t->Lchild = insert(t->Lchild, x);
    else
        t->Rchild = insert(t->Rchild, x);

    t->height = get_height(t);
    int bf = balance_factor(t);
    if(bf == 2 && balance_factor(t->Lchild) == 1)
        t = LLrotation(t);
    else if(bf == 2 && balance_factor(t->Lchild) == -1)
        t = LRrotation(t);
    else if(bf == -2 && balance_factor(t->Rchild) == -1)
        t = RRrotation(t);
    else if(bf == -2 && balance_factor(t->Rchild) == 1)
        t = RLrotation(t);

    return t;
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
        if(t->Lchild->height > t->Rchild->height)
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
    t->height = get_height(t);

    int bf = balance_factor(t);
    if(bf == 2 && balance_factor(t->Lchild) == 1)
        t = LLrotation(t);
    else if(bf == 2 && balance_factor(t->Lchild) == -1)
        t = LRrotation(t);
    else if(bf == -2 && balance_factor(t->Rchild) == -1)
        t = RRrotation(t);
    else if(bf == -2 && balance_factor(t->Rchild) == 1)
        t = RLrotation(t);
        
    return t;
}


int main()
{
    struct Tree *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 24);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 7);
    root = insert(root, 30);
    // root = insert(root, 36);
    // root = insert(root, 25);


    printf("\nPREORDER : ");
    preorder_recc(root);
    printf("\nINORDER : ");
    inorder_recc(root);

    return 0;
}
