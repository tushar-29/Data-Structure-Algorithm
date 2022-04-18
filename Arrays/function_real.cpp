#include<iostream>
#include<stdio.h>
using namespace std;

void show(int x, int y)
{
    cout<<"a = "<<x<<"\tb= "<<y<<endl;
}

int add(int x, int y)
{
    return x+y;
}

int mai()
{
    int a=10, b=20;

    void (*ptr_show)(int, int);  //function pointer decleration for void
    ptr_show = show; // initilising
    
    (*ptr_show)(a, b);

    int (*ptr_add)(int, int);
    ptr_add = add;

    cout<<(*ptr_add)(a, b);
    return 0;
}