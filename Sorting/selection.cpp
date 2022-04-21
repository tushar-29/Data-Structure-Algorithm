#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *arr, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

// no. of passes = n-1
// no. of comparsion = n(n-1)/2 = order(n^2); (always)
// no. of swaps = only 1 swap in ecah passes so for n passes= order(n)
// Time comp of selection sort is = Order(n^2)
//  Note : At each passes we get smallest element
// It is not adoptive
//  It is not stabel
// max and min comparison = order(n^2)

void selection(int *arr, int n)
{
    int i=0, j=0, pos=0;
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1;  j<n;  j++)
        {
            if(arr[pos] > arr[j])
                pos = j;
        }
        swap(&arr[i], &arr[pos]);
    }
}

int main()
{
    int array[10]={50, 20, 80, 60, 90, 30, 10, 40, 80, 70};
    selection(array, 10);
    display(array, 10);
    return 0;
}