#include<stdio.h>


int power(int x, int n)
{
    int i=0, product=1;
    for(i=0; i<n; i++)
        product *= x;
    return product;
}

int tree_height(int n)
{
    int count=0, i=0;
    while(!(n > power(2, i) && n <= power(2, i+1)))
        i++;
    return i+1;
}

void display(int *arr, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}
//  It take n times
//  Mearging take space so Space Comp = order(n)
// 
void mearging(int *arr, int l, int m, int h)
{
    int b[20];  // h-l+1
    int j=m+1, k=0, i=l;
    while(i<=m && j<=h)
    {
        if(arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    for(; i<=m; i++)
        b[k++] = arr[i];
    for(; j<=h; j++)
        b[k++] = arr[j];

    for(i=l, j=0; i<=h; i++, j++)
        arr[i] = b[j];
}

// Loop is repeated for logn times and merging take n time so
//  Time Comp = order(nlogn) time
// 
void mearge_sort(int *arr, int n)
{
    int p=0, q=0, k=0, low=0, mid=0, high=0, height= tree_height(n-1);

    for(p=1; p<=height; p++)
    {
        k = power(2, p);
        for(q=0; q<n-1; q=q+k)
        {
            low = q;
            high = q + k - 1;
            mid = (low + high) / 2;
            mearging(arr, low, mid, high);
            display(arr, n);
        }
    }
    if(n % 2 != 0)
        mearging(arr, 0, n-2, n-1);
}

// Time Comp = order(nlogn)
//  size of stack used = logn
// extra array space = n;
//  array of size = n
//  Total Space = 2n+logn
void recc_mearge_sort(int *arr, int l, int h)
{
    int mid=0;
    if(l<h)
    {
        mid = (l+h) /2;
        recc_mearge_sort(arr, l , mid);
        recc_mearge_sort(arr, mid+1, h);
        mearging(arr, l, mid, h);
    }
}

int main()
{
    int array[15] = {7, 3, 9, 1, 2, 5, 4, 6, 8, 15, 14, 13, 12, 11, 10};
    int n = 15;
    // mearge_sort(array, n);
    recc_mearge_sort(array, 0, n-1);
    display(array, n);
    return 0;
}