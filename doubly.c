#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next, *prev;
}*first=NULL;

void display()  //pass by value pointer
{
    struct Node *p=first; 
    if(!p){
        printf("YOUR LIST IS EMPTY\n");
        return;
    }
    printf("Your Linked List is : \n");
    while(p)
    {
        printf("%d\t", p->data);
        p= p->next;
    }
    printf("\n");
}

int count()
{
    struct Node *p=first; 
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
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
    temp->next = temp->prev = NULL;

    if(pos == 1)
    {
        if(p){
            temp->next = p;
            p->prev = temp;
        }

        first = temp;
    }
    else if(pos > 1 && pos <= count()+1)    // +1 since to add at last
    {
        int i=0;
        for(i=1; i<pos-1; i++)
            p = p->next;

        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
        if(temp->next)
            temp->next->prev = temp;
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
        return x;
    }
    else if(pos == 1)
    {
        first = p->next;
        x = p->data;
        if(first)
            first->prev = NULL;
        free(p);
    }
    else if(pos > 1 && pos <= count())
    {
        int i=0;
        for(i=1; i<pos; i++)
            p = p->next; 

        x = p->data;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev; 
        free(p);
    }
    else
        printf("Incorrect Position given\n");

    return x;
}


int menu_driven()
{
    int choice=0;
    int num=0, pos=0;
    
    printf("\t\tDOUBLY LINKED LIST\n\n");
    printf("1) INSERT AT END OF THE LIST\n");
    printf("2) INSERT AT ANY GIVEN POSITION OF THE LIST\n");
    printf("3) DELETE AT END OF LIST\n");
    printf("4) DELETE AT GIVEN POSITION OF THE LIST\n");
    printf("5) DISPLAY\n");
    printf("6) EXIT\n");
    printf("Enter your choice => ");
    scanf("%d", &choice);
    
    system("clear");
    switch(choice)
    {
        case 1:
            printf("\n\tINSERTION at given position of the DOUBLY Linked List\n\n");
            printf("\nEnter the number to insert : ");
            scanf("%d", &num);
            pos = -1;
            insert(pos, num);
            break;
            
            
        case 2:
            printf("\n\tINSERTION at last position of the DOUBLY Linked List\n\n");
            printf("\nEnter the number to insert : ");
            scanf("%d", &num);
            printf("Enter the position to be inserted : ");
            scanf("%d", &pos);
            insert(pos, num);
            break;
        
        case 3:
            printf("\n\tDELETION at last position of the DOUBLY Linked List\n\n");
            pos = -1;
            num = del_node(pos);
            if(num != -1)
                printf("\n%d has been deleted.\n", num);
            break;

        case 4:
            printf("\n\tDELETION at given position of the DOUBLY Linked List\n\n");
            printf("Enter the position of node to be deleted : ");
            scanf("%d", &pos);
            num = del_node(pos);
            if(num != -1)
                printf("\n%d has been deleted.\n", num);
            break;
        
        case 5:
            printf("\n\tDisplay\n\n");
            display();
            break;
        
        case 6:
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
