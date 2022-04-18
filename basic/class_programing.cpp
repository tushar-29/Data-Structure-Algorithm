#include<iostream>
#include<stdio.h>
using namespace std;

class Rectangle
{
    public:
     int length, breath;

    public:
    Rectangle(){length = breath = 1;}
    Rectangle(int l, int b);
    void change_length(int l=1);
    void change_breath(int b=1);
    int area();
};

Rectangle :: Rectangle(int l, int b)
{
    length = l;
    breath = b;
}

void Rectangle :: change_length(int l)
{
    length = l;
}

void Rectangle :: change_breath(int b)
{
    breath = b;
}

int Rectangle :: area()
{
    return (length * breath); 
}

int main()
{
    Rectangle r={10, 20};
    cout<<"Length = "<<r.length<<endl;
    cout<<"Breath = "<<r.breath<<endl;
    cout<<"Area = "<<r.area()<<endl<<endl;
    r.change_length(100);
    r.change_breath(200);
    cout<<"New length = "<<r.length<<endl;
    cout<<"New breath = "<<r.breath<<endl;
    cout<<"Area = "<<r.area()<<endl;
    Rectangle r2;
cout<<"r2 length = "<<r2.length<<endl;
cout<<"r2 breath = "<<r2.breath<<endl;
}
