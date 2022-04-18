#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    /* data */
    int length, breath;
};

int main()
{
    struct Rectangle r={15, 2};
    printf("length = %d\n", r.length);
    printf("breath  = %d\n", r.breath);
    Rectangle *p = &r;
    (*p).length = 20;   // '.' operator is more precidence then '*' so it get executed first so to stop this bracket is used or 
                                // we can use this directly '->'. 
    printf("new length = %d\n", p->length);

    // using heap memeory 

    Rectangle *q;
    q = (struct Rectangle *)malloc(sizeof(Rectangle));  // in c++ just write: new Rectangle
    q->length = 40;
    q->breath = 2;
    printf("heap length = %d\n", q->length);
    printf("heap breath = %d\n", q->breath);
    free(q);    //or in c++ write delete q;
    return 0;
}