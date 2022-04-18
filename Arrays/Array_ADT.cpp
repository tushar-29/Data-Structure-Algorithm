#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define clrscr() printf("\e[1;1H\e[2J")

struct ArrayBase
{
    int *arr, length, size;
};

void array_initialisation(struct ArrayBase *s, int n)
{
    s->arr =(int *)malloc(n * sizeof(int));
    s->length = 0;
    s->size = n;
}

void go_back()
{
    char ch;
    printf("\n Press enter to go back : ");
    getch();
}

void array_display(struct ArrayBase s)
{
    int i=0;
    if(s.length == 0)
        printf("YOUR ARRAY DOES NOT CONTAIN ANY VALUES\n");
    else
    {
        printf("Your array is : ");
        for(i=0; i<s.length; i++)
            printf("\t%d", s.arr[i]);
        printf("\n");
    }
    go_back();
}

void insert(struct ArrayBase *s)
{
    int i = 0, x=0, index=s->length;

    if( !( (s->size == 0) || (s->length >= s->size) ) )
    {
        printf("Enter the element to insert = ");
        scanf("%d", &x);
        printf("Enter the index of the number = ");
        scanf("%d", &index);
        index--;
        if(index <= s->length && index >= 0)
        {
            for(i=s->length; i>index; i--)
                s->arr[s->length] = s->arr[s->length - 1];
            s->arr[index] = x;
            s->length++;
            printf("%d has been inserted sucessfully\n", x);
        }
        else
            printf("Incorrect index\n");
    }
    else
        printf("No Space to add any element in the array\n");
    
    go_back();
} 

void set(struct ArrayBase *s)
{
    int i, x, index, del_element;
    if( !( (s->size == 0) || (s->length == 0) ) )
    {
        printf("Enter the index of the element to replace = ");
        scanf("%d", &index);
        printf("Enter the element to replace = ");
        scanf("%d", &x);
        index--;
        if(index < s->length && index >=0)
        {
            del_element = s->arr[index];
            s->arr[index] = x;
            printf("%d has been replace with %d\n", del_element, x);
        }
        else
            printf("Incorrect index\n");
    }
    else
        printf("No element present in the array.\n");
    
    go_back();
}


void get(struct ArrayBase s)
{
    int index;
    if( !( (s.size == 0) || (s.length == 0) ) )
    {
        printf("Enter the elements index = ");
        scanf("%d", &index);
        index--;
        if(index < s.length && index >=0)
            printf("Element at %d index is %d\n", index, s.arr[index]);
        else
            printf("Incorrect Index\n");
    }
    else
        printf("No Element present in the array\n");
    
    go_back();
}

void pop(struct ArrayBase *s)
{
     int i = 0, index=s->length-1, del_element;

    if( !( (s->size == 0) || (s->length >= s->size) ) )
    {
        printf("Enter the index of the number to be poped out= ");
        scanf("%d", &index);
        index--;
        if(index <= s->length && index >= 0)
        {
            s->arr[index] = del_element;
            for(i=index; i>s->length; i++)
                s->arr[i] = s->arr[i+1];
            s->length--;
            printf("%d has been poped out sucessfully\n", del_element);
        }
        else
            printf("Incorrect index\n");
    }
    else
        printf("There is no element present in the array\n");

    go_back();
}

int main()
{
    clrscr();
    int n=0;
    printf("Enter the length of the array = ");
    scanf("%d", &n);

    struct ArrayBase s;
    array_initialisation(&s, n);

    int loop = 1;

    while (loop)
    {
        clrscr();
        int z=0;
        printf("Array of Length %d has been created\n\n", s.size);
        printf("\t\tWelcome to Array ADT \n\n");
        printf("\t1)Displaying the value\n");
        printf("\t2)Insert a value at particular index\n");
        printf("\t3)set a element a particular index\n");
        printf("\t4)Get the value at that index\n");
        printf("\t5)Deleting a element at given index\n");
        printf("\t0) Exit \n\n");
        printf("Enter your choice = ");
        scanf("%d", &z);

        clrscr();
    
        printf("\nArray size = %d\tArray length = %d\n\n", s.size, s.length);
        switch (z)
        {
            case 1: 
                array_display(s);
                break;

            case 2: 
                insert(&s);
                break;
            
            case 3: 
                set(&s);
                break;

            case 4: 
                get(s);
                break;

            case 5: 
                pop(&s);
                break;

            case 0: 
                loop = 0;
                break;

            default:
                {
                    printf("Incorrect Choice no. \nPress Enter to go back");
                    getch();
                }
        }
    }
    free(s.arr);
    return 0;
}
