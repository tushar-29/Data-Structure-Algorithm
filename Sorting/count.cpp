#include<stdio.h>

void display(int *arr, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int max(int *arr, int n)
{
    int i=0, large=arr[0];
    for(i=1; i<n; i++)
    {
        if(large < arr[i])
            large = arr[i];
    }
    return large;
}

// Time Comp = order(n)
//  Space Comp = order(n)
void count_sort(int *arr, int n)
{
    int ind = max(arr, n) + 1;
    int i=0, j=0, k=0, count[ind] = {0};
    for(i=0; i<n; i++)
        count[arr[i]]++;
    
    for(i=0; i<ind; i++)
    {
        if(count[i] != 0)
        {
            for(j=0; j<count[i]; j++)
                arr[k++] = i;
        }
    }
}

int main()
{
    int array[12] = {6, 8, 3, 9, 3, 3, 6, 5, 4, 1, 1, 3};
    int n = 12;
    count_sort(array, n);
    display(array, n);
    return 0;
}
