#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
     
    public:

        SinglyCLL() 
        {
            cout<<"Inside Constructor of SinglyCLL\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }  
        
        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;                // Dynamic memory allocation

            newn->data = no;
            newn->next = NULL;

            if((first == NULL) && (last == NULL))                         // if(iCount == 0)     Singly CLL is empty
            {
                first = newn;
                last = newn;

                last->next = first;
            }
            else                                                           // if(iCount == 1)      Singlly CLL contains one node
            {
                newn->next = first;
                first = newn;

                last->next = first;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;                // Dynamic memory allocation

            newn->data = no;
            newn->next = NULL;

            if((first == NULL) && (last == NULL))                         // if(iCount == 0)     Singly CLL is empty
            {
                first = newn;
                last = newn;
                
                last->next = newn;
            }
            else                                                           // if(iCount == 1)      Singlly CLL contains one node
            {
                last->next = newn;
                last = newn;

                last->next = first;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                first = first -> next;
                delete last-> next;

                last-> next = first;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;

                while(temp-> next != last)
                {
                    temp = temp-> next;
                }

                delete last;
                last = temp;

                last-> next = first;
            }

            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = first;

            if((first == NULL) && (last == NULL))
            {
                return;
            }

            do
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp-> next;

            } while (temp != last-> next);

            cout<<"\n";
            
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int i = 0;

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

                temp = first;

                for(i = 1; i < pos-1; i++)
                {
                    temp = temp -> next;
                }

                newn->next = temp -> next;
                temp-> next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int i = 0;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount+1)
            {
                DeleteLast();
            }
            else
            {
                temp = first;

                for(i = 1; i < pos-1; i++)
                {
                    temp = temp-> next;
                }

                target = temp-> next;
                temp->next = target-> next;
                delete target;

                iCount--;
            }
        }
};

int main()
{
    SinglyCLL sobj;
    int iChoice = 0;                        
    int iValue = 0, iPos = 0, iRet = 0;

    cout<<"-------------------------------------------------------------------\n";
    cout<<"----------------------Singly Circular Linked List--------------------\n";
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
            sobj.InsertFirst(iValue);
        }
        else if(iChoice == 2)
        {
            cout<<"Enter the data that you want to insert Last : \n";
            cin>>iValue;
            sobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            cout<<"Enter the data that you want to insert Last : \n";
            cin>>iValue;

            cout<<"Enter the position at which you want to insert : \n";
            cin>>iPos;

            sobj.InsertAtPos(iValue,iPos);
        }
        else if(iChoice == 4)
        {
            cout<<"Deleting the first element from the Linked List";

            sobj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            cout<<"Deleting the last element from the Linked List";

            sobj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            cout<<"Deleting the element from the given position\n";

            cout<<"Enter the position from which you want to delete : \n";
            cin>>iPos;

            sobj.DeleteAtPos(iPos);
        }
        else if(iChoice == 7)
        {
            cout<<"Elements of the linked list are : \n";

            sobj.Display();
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
}  