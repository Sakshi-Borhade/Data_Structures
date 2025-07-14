#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void push(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | \n",first->data);
        first = first -> next;
    }
    printf("\n");
}

int pop(PPNODE first)
{
    PNODE temp = *first;

    if(*first == NULL)
    {
        printf("Unable to pop as stack is empty\n");
        return -1;
    }
    else
    {
        *first = (*first)->next;
        return temp->data;
    }
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iChoice = 0, iValue = 0, iRet = 0;

    printf("-------------------------------------------------------------------\n");
    printf("---------------------------------Stack-----------------------------\n");
    printf("-------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("-------------------------------------------------------------------\n");
        printf("----------------------Please Select the option----------------------\n");
        printf("-------------------------------------------------------------------\n");

        printf("1 : Insert new node in the Stack\n");
        printf("2 : Remove element from the stack\n");
        printf("3 : Display all elements from the stack\n");
        printf("4 : Count all the elements from the stack\n");
        printf("0 : Terminate the position\n");
        printf("-------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the data that you want to insert : \n");
            scanf("%d",&iValue);
            push(&head,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Remove the element from the stack\n");
            iRet = pop(&head);
            printf("Removed element from the stack is : %d\n",iRet);
        }
        else if(iChoice == 3)
        {
            Display(head);
        }
        else if(iChoice == 4)
        {
            iRet = Count(head);
            printf("The number of elements in the stack are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for using our application\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("\n-------------------------------------------------------------------\n");
    }

    return 0;
}