#include<iostream>
using namespace std;

// https://www.log2base2.com/C/pointer/2d-array-and-pointers-in-c.html

int main()
{
    // 2D array logic

    int arr[3][3]={{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    // now space is created is &arr 
    // arr is the address of the whole 0th row in the 2D array

    cout<<"Address of space is ="<<&arr<<endl;

    //address of the row pointer or address or row array
    cout<<"Address of 0th row in the 2D array is in space &arr="<<(arr+0)<<"\tor\t"<<arr[0]<<endl;

    cout<<"Address of 1th row  in 2D array is = "<<(arr+1)<<"\tor\t"<<arr[1]<<endl;

    // address of each cell in the row is                                                                                     
    cout<<"Address of 0th column of 0th row = "<<*(arr+0)+0<<"\tor\t"<<&arr[0][0]<<endl;
    cout<<"Address of 1th column of 0th row = "<<*(arr+0)+1<<"\tor\t"<<&arr[0][1]<<endl;
    cout<<"Address of 1th colum of 2th row = "<<*(arr+1)+2<<"\tor\t"<<&arr[1][2]<<endl<<endl;

    //here pointer is row no. and bracket as column no.
    cout<<"Address of oth row and 0th column = "<<&( (*arr) [0] )<<endl; // (*arr) is row no. and [0] is col no.
    cout<<"Address of 1th row and 2th column = "<<&( (*(arr+1)) [2] )<<endl<<endl; // (*(arr+1)) is row no. and [2] is col.no

    // here pointr is column no. and bracket as row no.
    cout<<"Value of 1th row and 1column = "<< *(arr[1]+1)<<endl; // here row is [2] and column is +1
    cout<<"Value of 2row and 1column = "<<*(arr[2]+1)<<endl;


    //value of the cells
    cout<<"Value of 2row 2column = "<<*(*(arr+2)+2)<<"\tor\t"<<arr[2][2]<<endl;
    cout<<"Value of 0row 1column = "<<*(*(arr+0)+1)<<"\tor\t"<<arr[0][1]<<endl;
    cout<<"Value of 1row 2column = "<<*(*(arr+1)+2)<<"\tor\t"<<arr[1][2]<<endl;

    cout<<"Value of oth row and 0th column = "<<(*(arr+0)) [0]<<endl; // (*arr) is row no. and [0] is col no. or  (*arr)[0]
    cout<<"Value of 1th row and 2th column = "<<(*(arr+1)) [2]<<endl<<endl; // (*(arr+1)) is row no. and [2] is col.no

}
