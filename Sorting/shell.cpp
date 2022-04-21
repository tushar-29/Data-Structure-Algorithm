#include<stdio.h>

void display(int *arr, int n)
{
    int i = 0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Time comp = nlogn time
//  This is adoptive in nature
// If gap is taken as Prime no. then Time Comp = n^(2/3);
void shell(int *arr, int n)
{
    int i=0, j=0, gap=0;
    // logn time 
    for(gap=n/2; gap > 0; gap /= 2)
    {
        // n time
        for(i=gap; i<n; i++)
        {

           for(j=i-gap; j>=0; j -= gap)
            {
                if(arr[j] > arr[j+gap])
                    swap(&arr[j] , &arr[j+gap]);
                else
                    break;
                display(arr, n);
            }
        }
    }
}

int main()
{
    int array[11] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
    int n=11;
    display(array, n);
    shell(array, n);
    display(array, n);
    return 0;
}