#include <stdio.h>

struct Rectangle
{
    int length, breath;
};

void initalisation(struct Rectangle *r, int l=0, int b=0)
{
    r->length = l;
    r->breath = b;
}

int area(struct Rectangle r)
{
    return (r.breath * r.length);
}

void change_length(struct Rectangle *r, int l)
{
    r->length = l;
}

void change_breath(struct Rectangle *r, int b)
{
    r->breath = b;
}

int main()
{
    struct Rectangle r={0, 0};
    initalisation(&r, 10, 20);
    printf("length = %d\nbreath = %d\n", r.length, r.breath);
    printf("area = %d\n", area(r));
    change_length(&r, 100);
    change_breath(&r, 200);
    printf("\nNew length = %d\nNew breath = %d\n", r.length, r.breath);
    printf("new area = %d", area(r));
    return 0;
}