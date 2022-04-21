#include<stdio.h>
#include<stdlib.h>


// Height is 2log()
struct Tree 
{
    struct Tree *Lchild;
    int data;
    int color;
    struct Tree *Rchild;
}*root=NULL;
// 1 = black and 0 = red

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

struct Tree * recoloring(struct Tree *grandpa, struct Tree *t, int flag)
{
    if(flag == 0)
    {
        grandpa->color = 0;
        t->color = 1;
        if(grandpa->Lchild == t)
        {
            if(grandpa->Rchild)
                grandpa->Rchild->color = 1;
        }
        else
            {
                if(grandpa->Lchild)
                    grandpa->Lchild->color = 1;
            }
    }
else
{
    grandpa->color = 1;
    t->color = 0;
}
    return grandpa;
}

struct Tree * zigzig_rotation(struct Tree *grandpa, struct Tree *t, int flag)
{
    if(grandpa->Lchild == t)
    {
        grandpa->Lchild = t->Rchild != NULL ? t->Rchild : NULL;
        t->Rchild = grandpa;
    }
    else
    {
        grandpa->Rchild = t->Lchild != NULL ? t->Lchild : NULL;
        t->Lchild = grandpa;
    }
    if(flag == 0)
    {
        t->color = 1;
        grandpa->color = 0;
    }
    else
    {
        // for deletion
        if(grandpa->color == 1 && t->color == 0)
        {
            grandpa->color = 0;
            t->color = 1;
        }
        else
        {
            grandpa->color = 1;
            t->color = 0;
        }

        if(t->Rchild == grandpa)
        {
            if(t->Lchild)
                t->Lchild->color = 0;
        }
        else
        {
            if(t->Rchild)
                t->Rchild->color = 0;
        }
        
    }
    return t;
}

struct Tree * zigzag_rotation(struct Tree *grandpa, struct Tree *t, int flag)
{
    struct Tree *child=NULL;
    if(grandpa->Lchild == t)
    {
        child = t->Rchild;
        grandpa->Lchild = child->Rchild != NULL ? child->Rchild : NULL;
        child->Rchild = grandpa;
        t->Rchild = child->Lchild != NULL ? child->Lchild : NULL;
        child->Lchild = t;
    }
    else
    {
        child = t->Lchild;
        grandpa->Rchild = child->Lchild !=NULL ? child->Lchild : NULL;
        child->Lchild = grandpa;
        t->Lchild = child->Rchild != NULL ? child->Lchild : NULL;
        child->Rchild = t;
    }
    if(flag == 0)
    {
        child->color = 1;
        grandpa->color = 0;
        t->color = 0;
    }
    else
    {
        //for deletion 
        child->color = 0;
        t->color = 1;
        grandpa->color = 1;
    }
    return child;
}

struct Tree * insertion_checking(struct Tree *t)
{
    if(t->Lchild && t->Lchild->color == 0 && t->Lchild->Lchild && t->Lchild->Lchild->color == 0)
        {
            if(t->Rchild && t->Rchild->color == 0)
                t = recoloring(t, t->Lchild, 0);
            else
                t = zigzig_rotation(t, t->Lchild, 0);
            t = insertion_checking(t);
        }
    else if(t->Lchild && t->Lchild->color == 0 && t->Lchild->Rchild && t->Lchild->Rchild->color == 0)
        t = zigzag_rotation(t, t->Lchild, 0);

    else if(t->Rchild && t->Rchild->color == 0 && t->Rchild->Rchild && t->Rchild->Rchild->color == 0)
        {
            if(t->Lchild && t->Lchild->color == 0)
                t = recoloring(t, t->Rchild, 0);
            else
                t = zigzig_rotation(t, t->Rchild, 0);
            t = insertion_checking(t);
        }
    else if(t->Rchild && t->Rchild->color == 0 && t->Rchild->Lchild && t->Rchild->Lchild->color == 0)
        t = zigzag_rotation(t, t->Rchild, 0);

    if(t == root)
        t->color = 1;
    return t;
}

struct Tree * deletion_checking(struct Tree *t)
{
    struct Tree *temp= NULL;
    if(t->Lchild && t->Lchild->color == 2)
    {
        temp = t->Lchild;
        free(temp);
        t->Lchild = NULL;
        if(t->color == 0 && t->Rchild && t->Rchild->color == 1)
            t = recoloring(t, t->Rchild, 1);
        else if(t->color == 1 && t->Rchild && t->Rchild->color == 1)
            {
                if(t->Rchild->Lchild && t->Rchild->Lchild->color == 0)
                    t = zigzag_rotation(t, t->Rchild, 1);
                else
                    t = zigzig_rotation(t, t->Rchild, 1);
            }
        else if(t->color == 1 && t->Rchild && t->Rchild->color == 0)
            t = zigzig_rotation(t, t->Rchild, 1);
    }

    else if(t->Rchild && t->Rchild->color == 2)
    {
        temp = t->Rchild;
        free(temp);
        t->Rchild = NULL;
        if(t->color == 0 && t->Lchild && t->Lchild->color == 1)
            t = recoloring(t, t->Lchild, 0);
        else if(t->color == 1 && t->Rchild && t->Rchild->color == 1)
            {
                if(t->Lchild->Rchild && t->Lchild->Rchild->color == 0)
                    t = zigzag_rotation(t, t->Lchild, 1);
                else
                    t = zigzig_rotation(t, t->Lchild, 1);
            }
        else if(t->color == 1 && t->Lchild && t->Lchild->color == 0)
            t = zigzig_rotation(t, t->Lchild, 1);
    }

    if(t == root)
        t->color = 1;
    
    return t;
}

struct Tree * insert(int x, struct Tree *t = root)
{
    if(!t)
    {
        struct Tree *temp = (struct Tree *)malloc(sizeof(struct Tree));
        temp->data = x;
        temp->Lchild = temp->Rchild = NULL;
        temp->color = 0;
        return temp;
    }
    if(t->data > x)
        t->Lchild = insert(x, t->Lchild);
    else if(t->data < x)
        t->Rchild = insert(x, t->Rchild);
    else
        printf("Error: Element %d already Exist in the Tree\n", x);

    t = insertion_checking(t);
    return t;
}

struct Tree * del(int  x, struct Tree *t=root)
{
    if(t == NULL)
    {
        printf("Element %d not in the Tree", x);
        return NULL;
    }
    else if(!t->Lchild && !t->Rchild && t->data == x)
    {
        if(t->color == 0 || t == root)
        {
            free(t);
            return NULL;
        }
        else
            t->color = 2; // double black
    }

    else if(t->data > x)
        t->Lchild = del(x, t->Lchild);
    else if(t->data < x)
        t->Rchild = del(x, t->Rchild);
    else
    {
        struct Tree *temp = NULL;
        if(height(t->Lchild) > height(t->Rchild))
        {
            temp = inorder_pre(t->Lchild);
            t->data = temp->data;
            t->Lchild = del(temp->data, t->Lchild);
        }
        else
        {
            temp = inorder_succ(t->Rchild);
            t->data = temp->data;
            t->Rchild = del(temp->data, t->Rchild);
        }
    }
    t = deletion_checking(t);
    t = insertion_checking(t);
    return t;
}

void inorder_recc(struct Tree *p)
{
    if(p)
    {
        inorder_recc(p->Lchild);
        printf("%d\t", p->data);
        inorder_recc(p->Rchild);
    }
}

int main()
{
    root = insert(60);
    inorder_recc(root);
    printf("\n");
    root = insert(20);
    inorder_recc(root);
    printf("\n");
    root = insert(45);
    inorder_recc(root);
    printf("\n");
    root = insert(5);
    inorder_recc(root);
    printf("\n");
    root = insert(35);
    inorder_recc(root);
    printf("\n");
    root = insert(75);
    inorder_recc(root);
    printf("\n");
    root = insert(50);
    inorder_recc(root);
    printf("\n");
    root = insert(40);
    inorder_recc(root);
    printf("\n");
    root = insert(100);
    inorder_recc(root);
    printf("\n");
    root = insert(90);
    inorder_recc(root);
    printf("\n");
    root = insert(95);
    inorder_recc(root);
    printf("\n");
    root = insert(80);
    inorder_recc(root);
    printf("\n");
    root = insert(10);
    inorder_recc(root);
    printf("\n");
    root = insert(30);
    inorder_recc(root);
    printf("\n");
    root = insert(15);
    inorder_recc(root);
    printf("\n");
    root = insert(55);
    inorder_recc(root);
    printf("\n");
    root = insert(25);
    inorder_recc(root);
    printf("\n");
    root = insert(65);
    inorder_recc(root);
    printf("\n");
    root = insert(70);
    inorder_recc(root);
    printf("\n");
    root = insert(85);
    inorder_recc(root);
    printf("\n");

    printf("\ndeletion : \n");
    root = del(65);
    inorder_recc(root);
    printf("\n");
    root = del(70);
    inorder_recc(root);
    printf("\n");
    root = del(5);
    inorder_recc(root);
    printf("\n");
    root = del(15);
    inorder_recc(root);
    printf("\n");
    root = del(10);
    inorder_recc(root);
    printf("\n");

    root = insert(27);
    inorder_recc(root);
    printf("\n");

    root = del(20);
    inorder_recc(root);
    printf("\n");
}
