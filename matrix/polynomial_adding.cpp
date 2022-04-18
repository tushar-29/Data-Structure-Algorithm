#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Term
{
    int coff, expo;
};

struct Poly
{
    int terms;
    struct Term *eq;
};

void creat(struct Poly *p, int highest_deg)
{
    p->terms = highest_deg+1;
    p->eq = (struct Term *)malloc(p->terms * sizeof(struct Term));
}

void display(struct Poly p)
{
    int i;
    printf("Exuation is : \n");
    for(i=0; i<p.terms; i++)
        printf("\t+\t(%d)x^%d", p.eq[i].coff, p.eq[i].expo);
    printf("\n");
}

int evaluate(struct Poly p, int x)
{
    int i, sum=0;
    for(i=0; i<p.terms; i++)
        sum += (p.eq[i].coff * pow(x, p.eq[i].expo));
    return sum;
}

struct Poly * add(struct Poly p1, struct Poly p2)
{
    struct Poly *p3;
    p1.terms >= p2.terms ? creat(p3, p1.terms) : creat(p3, p2.terms);
    int i=0, j=0, k=0;
    while(k <= p3->terms)
    {
        if(p1.eq[i].expo > p2.eq[j].expo)
            p3->eq[k++] = p1.eq[i++];
        else if (p1.eq[i].expo < p2.eq[j].expo)
            p3->eq[k++] = p2.eq[j++];
        else 
        {
            p3->eq[k] = p1.eq[i++];
            p3->eq[k++].coff += p2.eq[j++].coff;
        }
    }
    return p3;
}

int main()
{
    struct Poly p1;
    // no. of tearms = higest degree + 1
    creat(&p1, 5);
    int i;
    for(i=0; i<p1.terms; i++)
    {
        printf("Enter the cofficient of x to power %d = ", p1.terms-i-1);
        scanf("%d", &p1.eq[i].coff);
        p1.eq[i].expo = p1.terms - i - 1;
    }
    display(p1);
    printf("Solution of equation 1 = %d\n", evaluate(p1, 2));

    struct Poly p2;
    creat(&p2, 7);

    for(i=0; i<p2.terms; i++)
    {
        printf("Enter the cofficient of x to power %d = ", p2.terms-i-1);
        scanf("%d", &p2.eq[i].coff);
        p2.eq[i].expo = p2.terms - i - 1;
    }
    display(p2);
    printf("Solution of equation 2 = %d\n", evaluate(p2, 2));

    struct Poly *p3;
    p3 = add(p1, p2);

    printf("Solution of adding eq1 + eq2 together = %d\n", evaluate(*p3, 2));
    return 0;
}
