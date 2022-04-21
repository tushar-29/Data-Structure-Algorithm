#include<stdio.h>
#include<stdlib.h>

struct Tree
{
    struct Tree *Lchild;
    int d1;
    struct Tree *Mchild;
    int d2;
    struct Tree *Rchild;
    int d3;
    struct Tree *Sub;
};


