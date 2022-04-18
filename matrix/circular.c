/*
Step 1:  START
Step 2:  Invoke struct Node function
Step 3:  Declare data as integer data-type variable and call struct Node *next, *previous pointers.
Step 4:  *first=NULL
Step 5:  Invoke void display function.
Step 6:  struct Node *p=first
          if(!p)
          Print YOUR LIST IS EMPTY and return.
Step 7:  Print your Linked List is : 
          while(p)
          Print the linked list input by user.
          p= p->next
Step 8:  Invoke int count function.
Step 9:  struct Node *p=first and declare int c=0.
Step 10: while(p)
          c++;
          p=p->next;
          and return c.
Step 11: Invoke void insert function and declare pos, x as integer data-type variable.
Step 12: struct Node *p=first
         if(pos == -1)
           pos = count() + 1
           struct Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = x;
            temp->next = temp->prev = NULL
Step 13: if(pos == 1)
          if(p)
            temp->next = p;
            p->prev = temp;
         
          first = temp
Step 14: else if(pos > 1 && pos <= count()+1)
           Declare int i=0
           Execute a for loop (i=1; i<pos-1; i++)
             p = p->next; 

             x = p->data;
             p->prev->next = p->next
           if(p->next)
            p->next->prev = p->prev; 
            free(p)
Step 15: else Print incorrect Position given and return x.
Step 16: Step 18: Invoke int menu_driven function.
Step 19: Declare int choice=0, int num=0, and pos=0
Step 20: Print       DOUBLY LINKED LIST
                 1) INSERT AT END OF THE LIST
                 2) INSERT AT ANY GIVEN POSITION OF THE LIST
                 3) DELETE AT END OF LIST
                 4) DELETE AT GIVEN POSITION OF THE LIST
                 5) DISPLAY
                 6) EXIT
                    Enter your choice => 

Step 21: Using switch case 
          
            Case 1: i)   Print INSERTION at given position of the Doubly Linked List
                    ii)  Print Enter the number to insert :   and take input from user.
                    iii)  pos = -1
                          insert(pos, num)
                    iv)  Break.
           
            Case 2: i)   Print INSERTION at last position of the Doubly Linked List
                    ii)  Print Enter the number to insert :   and take input from user.
                    iii) Print Enter the position to be inserted :  and take input from user.
                    iv)   insert(pos, num)
                    v)   Break.
          
            Case 3: i)   Print DELETION at last position of the Doubly Linked List
                    ii)  pos = -1;
                         num = del_node(pos);
                         if(num != -1)
                    iii) Print the number has been Deleted
                    iv)  Break
            
            Case 4: i)   Print DELETION at given position of the Doubly Linked List
                    ii)  Print Enter the position of node to be deleted :  and take input from user.
                    iii)  num = del_node(pos);
                                if(num != -1)
                    iv) Print the Number has been deleted.
                    
            Case 5: i)   Print Display
                    ii)  display()
                    iii) Break 
            
            Case 6: i)  Return 0
            
            Default: Print wrong input.
            
Step 22: Invoke int main function.
Step 23: Declare int flag=1 and ch as character data-type variable.
Step 24:  flag = menu_driven()
            while (flag)
         Print Press Enter to continue
Step 25:   ch = getchar();
          ch = getchar();
          system("clear");
          flag = menu_driven() 

Step 26: Return 0
Step 27: STOP
*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void display()
{
    struct Node *p=first;
    if(!p){
        printf("YOUR LIST IS EMPTY\n");
        return;
    }

    printf("Your Circular Linked List is : \n");
    do
    {
        printf("%d\t", p->data);
        p = p->next;
    }while(p != first);
    printf("\n");
}

int count()
{
    struct Node *p=first;
    int c=0;

    if(!p){
        return c;
    }
        
    do
    {
        c++;
        p=p->next;
    }while(p != first);

    return c;
}

void insert(int pos, int x)
{
    struct Node *p=first; 
    // insert at end of linked list
    if(pos == -1)
        pos = count() + 1; 

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = temp;

    if(pos == 1)
    {
        if(p)
        {
            temp->next = first;
            while(p->next != first)
                p = p->next;
            p->next = temp;
        }
        first = temp;
    }
    else if(pos > 1 && pos <= count() + 1)
    {
        int i=0;
        for(i=1; i<pos-1; i++)
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
    else
        printf("Incorrect Position given\n");
}

int del_node(int pos)
{
    struct Node *p=first;
    if(pos == -1)
        pos = count();

    int x=-1;
    if(p == NULL)
    {
        printf("No Node present to be deleted\n");
    }
    else if(pos == 1)
    {
        x = first->data;
        if(p->next == first)
        {
            free(p);
            first = NULL;
        }
        else
        {
            while(p->next != first)
                p = p->next;

            p->next = first->next;
            first = p->next;
        }
    }
    else if(pos > 1 && pos <= count())
    {
        int i=0;
        struct Node *q=p;
        for(i=1; i<pos; i++){
            q = p;
            p = p->next; 
        }
        x = p->data;
        q->next = p->next;
        free(p);
        return x;
    }
    else
        printf("Incorrect Position given\n");
    return x;
    
}


int menu_driven()
{
    int choice=0;
    int num=0, pos=0;
    
    printf("\t\tCIRCULAR LINKED LIST\n\n");
    printf("1) INSERT AT BEGINNING OF THE LIST\n");
    printf("2) INSERT AT END OF THE LIST\n");
    printf("3) INSERT AT ANY GIVEN POSITION OF THE LIST\n");
    printf("4) INSERT AT BEGINNING OF THE LIST\n");
    printf("5) DELETE AT END OF LIST\n");
    printf("6) DELETE AT GIVEN POSITION OF THE LIST\n");
    printf("7) DISPLAY\n");
    printf("8) EXIT\n");
    printf("Enter your choice => ");
    scanf("%d", &choice);
    
    system("clear");
    switch(choice)
    {
        case 1:
            printf("\n\tINSERTION at beginning of the Circular Linked List\n\n");
            printf("\nEnter the number to insert : ");
            scanf("%d", &num);
            pos = 1;
            insert(pos, num);
            break;

        case 2:
            printf("\n\tINSERTION at last position of the Circular Linked List\n\n");
            printf("\nEnter the number to insert : ");
            scanf("%d", &num);
            pos = -1;
            insert(pos, num);
            break;
            
        case 3:
            printf("\n\tINSERTION at given position of the Circular Linked List\n\n");
            printf("\nEnter the number to insert : ");
            scanf("%d", &num);
            printf("Enter the position to be inserted : ");
            scanf("%d", &pos);
            insert(pos, num);
            break;
            
        case 4:
            printf("\n\tDELETION at beginning of the Circular Linked List\n\n");
            pos = 1;
            num = del_node(pos);
            if(num != -1)
                printf("\n%d has been deleted.\n", num);
            break;

        case 5:
            printf("\n\tDELETION at last position of the Circular Linked List\n\n");
            pos = -1;
            num = del_node(pos);
            if(num != -1)
                printf("\n%d has been deleted.\n", num);
            break;

        case 6:
            printf("\n\tDELETION at given position of the Circular Linked List\n\n");
            printf("Enter the position of node to be deleted : ");
            scanf("%d", &pos);
            num = del_node(pos);
            if(num != -1)
                printf("\n%d has been deleted.\n", num);
            break;
        
        case 7:
            printf("\n\tDisplay\n\n");
            display();
            break;
        
        case 8:
            return 0;
            
        default:
            printf("\n\tWRONG INPUT\n");
    }
    
    return 1;
}


int main()
{
    int flag=1;
    char ch;

    flag = menu_driven();

    while(flag)
    {
        printf("Press Enter to continue\n");
        ch = getchar();
        ch = getchar();
        system("clear");
        flag = menu_driven();
    }
    
    return 0;
}
