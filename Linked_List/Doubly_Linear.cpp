#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class DoublyLLL
{
    private:
        PNODE first;
        int iCount;

    public:

        DoublyLLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;             

            if(first == NULL)                 
            {
                first = newn;
            }
            else                                 
            {
                newn->next = first;
                first-> prev = newn;            
                first = newn;
            }

            iCount++;
        }

        void Display()
        {
            cout<<" NULL -> ";
            while(first != NULL)
            {
                cout<<"| "<<first->data<<" | -> ";
                first = first->next;
            }
            cout<<"NULL\n";
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;             

            if(first == NULL)                 
            {
                first = newn;
            }
            else                                 
            {
                temp = first;

                while(temp-> next != NULL)
                {
                    temp = temp -> next;
                }

                newn -> prev = temp;             
                temp -> next = newn;
            }

            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if((first)-> next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                first = first -> next;  
                delete first-> prev;             
                first-> prev = NULL;             
            } 
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first-> next == NULL)
            {
                free(first);
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp-> next != NULL)           
                {
                    temp = temp-> next;
                }

                temp-> prev-> next = NULL;           
                delete temp;
            }
            iCount--;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;
            PNODE newn = NULL;
            PNODE temp = NULL;

            if((pos < 1) || (pos > iCount+1))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp -> next;
                }

                newn-> next = temp -> next;
                newn-> next->prev = newn;                  
                temp-> next = newn;
                newn-> prev = temp;                         
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp-> next;
                }

                target = temp -> next;
                temp-> next = target -> next;
                target-> next -> prev = temp;         
                delete target;
            }
        }            
};

int main()
{
    DoublyLLL dobj;
    int iChoice = 0;                        
    int iValue = 0, iPos = 0, iRet = 0;

    cout<<"-------------------------------------------------------------------\n";
    cout<<"----------------------Doubly Linear Linked List--------------------\n";
    cout<<"-------------------------------------------------------------------\n\n";

    while(1)
    {
        cout<<"-------------------------------------------------------------------\n";
        cout<<"----------------------Please Select the option----------------------\n";
        cout<<"-------------------------------------------------------------------\n";

        cout<<"1 : Insert new node at first position\n";
        cout<<"2 : Insert new node at last position\n";
        cout<<"3 : Insert new node at given position\n";
        cout<<"4 : Delete new node at first position\n";
        cout<<"5 : Delete new node at last position\n";
        cout<<"6 : Delete new node at given position\n";
        cout<<"7 : Display all elements of Linked list\n";
        cout<<"0 : Terminate the application\n";
        cout<<"-------------------------------------------------------------------\n";

        cin>>iChoice;

        if(iChoice == 1)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;
            dobj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
            cout<<"Enter the data that you want to insert Last : \n";
            cin>>iValue;
            dobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the data that you want to insert at position : \n";
            cin>>iValue;

            cout<<"Enter the position at which you want to insert : \n";
            cin>>iPos;

            dobj.InsertAtPos(iValue,iPos);
        }
        else if(iChoice == 4)
        {
            cout<<"Deleting the first element from the Linked List";

            dobj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            cout<<"Deleting the last element from the Linked List";

            dobj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            cout<<"Deleting the element from the given position\n";

            cout<<"Enter the position from which you want to delete : \n";
            cin>>iPos;

            dobj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"Elements of the linked list are : \n";

            dobj.Display();
        }
        else if(iChoice == 0)
        {
            cout<<"Thank you for using our application"<<"\n";
            break;
        }
        else
        {
            cout<<"Invalid choice\n";
        }
        cout<<"-------------------------------------------------------------------\n";
    }    

    return 0;
}