// Doubly linear Linked list
// | NULL | 11 | 200| -> | 100 | 21 | 300 | -> | 200 | 51 | NULL |

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;                     // $(change)
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first)
{
    printf(" NULL <=> ");
    while(first != NULL)
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first-> next;
    }
    return iCount;
}

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;             // $

    if(*first == NULL)                 // LL is empty
    {
        *first = newn;
    }
    else                                 // LL contains atleast one node
    {
        newn->next = *first;
        (*first)-> prev = newn;            // $
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;             // $

    if(*first == NULL)                 // LL is empty
    {
        *first = newn;
    }
    else                                 // LL contains atleast one node
    {
        temp = *first;

        while(temp-> next != NULL)
        {
            temp = temp -> next;
        }

        newn -> prev = temp;             // $
        temp -> next = newn;
    }
}

void DeleteFirst(PPNODE first)   // without temp
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)-> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first) -> next;  
        free((*first)-> prev);             // $
        (*first)-> prev = NULL;             // $
    } 
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)-> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp-> next != NULL)           // number 2 loop
        {
            temp = temp-> next;
        }

        temp-> prev-> next = NULL;           // $
        free(temp);
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{
   int iCount = 0, iCnt = 0;
   PNODE newn = NULL;
   PNODE temp = NULL;
   
   iCount = Count(*first);

   if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn-> next = temp -> next;
        newn-> next->prev = newn;                  // $
        temp-> next = newn;
        newn-> prev = temp;                         // $
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iCount = 0;
    int iCnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp-> next;
        }

        target = temp -> next;
        temp-> next = target -> next;
        target-> next -> prev = temp;         // $
        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    int iChoice = 0;                         // choice from user
    int iValue = 0, iPos = 0, iRet = 0;     // value to store data and Ret to count
    
    printf("-------------------------------------------------------------------\n");
    printf("----------------------Doubly Linear Linked List--------------------\n");
    printf("-------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("-------------------------------------------------------------------\n");
        printf("----------------------Please Select the option----------------------\n");
        printf("-------------------------------------------------------------------\n");

        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete new node at first position\n");
        printf("5 : Delete new node at last position\n");
        printf("6 : Delete new node at given position\n");
        printf("7 : Display all elements of Linked list\n");
        printf("8 : Count number of nodes of linked list\n");
        printf("0 : Terminate the application\n");
        printf("-------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);
            InsertFirst(&head,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that you want to insert Last : \n");
            scanf("%d",&iValue);
            InsertLast(&head,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that you want to insert Last : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from the Linked List");

            DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from the Linked List");

            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from the given position\n");

            printf("Enter the position from which you want to delete : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements of the linked list are : \n");

            Display(head);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head);
            printf("Number of elements in Linked list are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for using our application \n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("-------------------------------------------------------------------\n");
    }

    return 0;
}