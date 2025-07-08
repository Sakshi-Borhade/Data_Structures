#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }

    do
    {
        printf("<=> | %d | <=> ",(first)->data);
        first = (first)->next;
        
    } while (first != (last)->next);
    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if((first == NULL) && (last == NULL))
    {
        return iCount;
    }

    do
    {
        iCount++;
        first = first->next;
        
    } while (first != last->next);

    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*first)->next = *first;
        (*first)->prev = (*first)->next;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn->next;
        *first = newn;
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*first)->next = *first;
        (*first)->prev = (*first)->next;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        (*first)->prev = *last;
        free((*last)-> next);
        (*last)->next = *first;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;
        free((*last)->next);
        (*last)-> next = *first;
        (*first)->prev = *last;
    }
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int iCount = 0, iCnt = 0;
   PNODE newn = NULL;
   PNODE temp = NULL;
   
   iCount = Count(*first,*last);

   if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
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

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iCount = 0;
    int iCnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first,*last);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
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
    PNODE tail = NULL;
    int iChoice = 0;                        
    int iValue = 0, iPos = 0, iRet = 0;

    printf("-------------------------------------------------------------------\n");
    printf("----------------------Doubly Circular Linked List--------------------\n");
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
            InsertFirst(&head,&tail,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that you want to insert Last : \n");
            scanf("%d",&iValue);
            InsertLast(&head,&tail,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that you want to insert Last : \n");
            scanf("%d",&iValue);

            printf("Enter the position at which you want to insert : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head,&tail,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from the Linked List");

            DeleteFirst(&head,&tail);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from the Linked List");

            DeleteLast(&head,&tail);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from the given position\n");

            printf("Enter the position from which you want to delete : \n");
            scanf("%d",&iPos);

            DeleteAtPos(&head,&tail,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements of the linked list are : \n");

            Display(head,tail);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head,tail);
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
