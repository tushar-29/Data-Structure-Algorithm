#include<iostream>
using namespace std;

// https://www.log2base2.com/C/pointer/arr+1-vs-address-of-arr+1.html

int main()
{
    int arr[5]={100, 200, 300, 400, 500};

    // &arr is a space or pointer of type (int *)(int *) and 
    // &arr+0 is space in &arr and of type int(*)[5]
    // &arr+0 mean a space of 5 integer of size 20bytes since, 1 int take 4byte.
    cout<<"literally &arr+0 or &arr mean the base address of the space = "<<&arr<<"\tor\t"<<&arr+0<<endl;


    //note adding +1 in &arr+1 is not integer adding but its addrress adding
    // 1 does not mean add int value 1 but it mean adding base byte value 1 of that type
    //if &arr take address of 1000 in memory,  then &arr+1 take 1000+30=1030address
    // so here 30 is base byte for &arr

cout<<&(arr+3<<end)
    //but &arr+1 is another space of type int(*)[5] not same as &arr+0
    cout<<"address of another space &arr+1 will be = "<<&arr+1<<endl;

     //size of &arr or &arr+0 is 8 hence pointer take 8byte so arr is a pointrer variable of type (int *)[5]
    cout<<"size of pointer arr = "<<sizeof(&arr)<<endl;


    // address of 0th position of array  in space &arr+0 is :
    cout<<"address of 0th pos of array is = "<<arr+0<<"\tor\t"<<arr<<endl;

    // address of 2th position of array in space &arr+0 is: i.e base address + 8(arr+0 + 8bytes) 
    cout<<"address of 2th pos of array is"<<arr+2<<endl;

    //access value we can use = pointer(*) and address = value stored in that place 
    cout<<"value at 0th pos = "<<*(arr+0)<<"\tor\t"<<*arr<<"\tor\t"<<arr[0]<<endl;
    cout<<"value at 1th place = "<<*(arr+1)<<"\tor\t"<<arr[1]<<endl;

    cout<<endl<<endl<<endl;
//----------------------------------------------------------------------------------------------------------------------
    // accessing value using pointers

    int *p = arr; // declar and initialising array to pointer, space address is copied to p;
    // here arr itself an address so no need &arr to store it.

    // here arr is copied to p and p is of type `int`  that is 4byte.
    // address of 0th pos i.e arr or arr+1 is copied to integer pointer p.
    // same this is in parameter passing where argument is arr and paramenter is *p

    //accessing in function or in main    
    cout<<"address of 0th pos = "<<p+0<<"\tor\t"<<arr+0<<endl; // or p or arr
    cout<<"value at address 0th pos = "<<*(p+0)<<"\tor\t"<<p[0]<<"\tor\t"<<*(arr+0)<<endl;

    // hence *(arr+1) == arr[1] == *(p+1) == p[1]
    //note arr and p is base type int 

    cout<<"address of 1th pos = "<<p+1<<"\tor\t"<<arr+1<<endl; // or p or arr
    cout<<"value at address 1th pos = "<<*(p+1)<<"\tor\t"<<p[1]<<"\tor\t"<<*(arr+1)<<endl;

    p++;    //here address move from arr+0 ot arr+1
    //here only 1int i.e 4byte is added to p since p is pointer to single int value.
    //but &arr++ then size of array is added to &arr i.e &arr+1
    //&arr+1 = &arr + size  of &arr
    cout<<"address of p++ = "<<p<<"\tor\t"<<arr+1<<endl;
    cout<<"value of p++ = "<<*p<<"\tor\t"<<*(arr+1)<<endl;

    cout<<endl<<endl<<endl;
//----------------------------------------------------------------------------------------------------------------------

    // it is array pointer
    int (*ptr)[5]; // it is pointer which store array of length 5 only 
    // ptr++ mean ptr = address(ptr) + size of array of length 5 like &arr+1
    ptr = &arr; //here ptr directly store the space of &arr not singel arr+0


    // only one value is taken of that size ptr[0] = arr[0] but ptr[0] size is of whole arr but arr[0] is of int only.
     // but ptr[1] = is 2 * sizeof(arr) at that address value. which is not not not arr[1];

    //now ptr = &arr
    // *ptr = arr
    cout<<"address of array pointer = "<<ptr<<"\tor\t"<<&arr<<endl;
    cout<<"base address of pointer = "<<*(ptr+0)<<"\tor\t"<<arr+0<<endl;

    // value printing
    cout<<"value at base address = "<<**(ptr+0)<<"\tor\t"<<*(arr+0)<<"\tor\t"<<arr[0]<<"\tor\t"<<*ptr[0]<<endl;

    // **(ptr+0) == *(arr+0) == arr[0]
    // &arr and ptr are base type array of length 5 not type int like p or arr

    cout<<endl<<endl<<endl;
    //----------------------------------------------------------------------------------------------------------------------------

    // array of pointer

    int *a[3]; // array of pointer a store 3 address of int base type
    int i=10, j=20, k=30;
    a[0] = &i; a[1] = &j; a[2] = &k;

    cout<<"address of a(int *)[3] = "<<a<<"\tor\t"<<(a+0)<<endl;

    //address of each element
    // a == space containing 3 int pointer
    // *(a+0) or a[0] == base address of 0th position in array
    // **(a+0) or *a[0] == value at 0th position.

    // &i or &arr[0] or (arr+0)  or *(a+0) or a[0]  is the address variable
    // i or arr[0] or *(arr+0) or **(a+0) or *a[0] is value

    cout<<"address of a[0] = "<<a[0]<<"\tor\t"<<&i<<"\tor\t"<<*(a+0)<<endl;
    cout<<"address of a[1] = "<<a[1]<<"\tor\t"<<&j<<"\tor\t"<<*(a+1)<<endl;
    cout<<"address of a[2] = "<<a[2]<<"\tor\t"<<&k<<"\tor\t"<<*(a+2)<<endl;

    // value in the address 
    cout<<"value at a[0] = "<<*a[0]<<"\tor\t"<<i<<"\tor\t"<<**(a+0)<<endl;
    cout<<"value at a[1] = "<<*a[1]<<"\tor\t"<<j<<"\tor\t"<<**(a+1)<<endl;
    cout<<"value at a[2] = "<<*a[2]<<"\tor\t"<<k<<"\tor\t"<<**(a+2)<<endl;

    cout<<endl<<endl<<endl;

    //-----------------------------------------------------------------------------------------------------------------------

    return 0;
}
