#include <stdio.h>
using namespace std;
 struct Card
{
    int face, shape, color;
} r1, r2;

// global dicleration

int main ()
{
    int n;
    printf ("Enter the size of the array : ");
    scanf ("%d", &n);
    printf("\n");
    int A[n], i;
    // initialisation the array of n length
    A[0] = 22;
    A[2] = 44;
    printf("Array size = %d \n", sizeof(A));
    // sife occupied by array of length will be = space taken by 1 int * size of array i.e n
    printf("Your array is : ");
    for (i = 0; i < 5; i++)
        {
        printf ("\t%d", A[i]);
        }
    printf("\n");
    // Structure data type
    struct Card deck[52];		// deck is array of structure of length 52
    deck[0].color = 1;
    deck[0].face = 5;
    deck->shape = 3;
    printf("color=%d\nface=%d\nshape=%d\n", deck[0].color, deck[0].face, deck[0].shape);
    return 0;
}