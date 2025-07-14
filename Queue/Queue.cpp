#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class QueueX
{
    private :
        PNODE first;
        int iCount;

    public:
        QueueX()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void enqueue(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                temp = this->first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }

            iCount++;
        }

        int dequeue()
        {
            PNODE temp = first;

            if(this->first == NULL)
            {
                cout<<"Unable to remove as Queue is empty";
                return -1;
            }
            else
            {
                first = first->next;
                iCount--;
                return temp->data;
            }
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | - ";
                temp = temp->next;
            }
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    QueueX sobj;
    int iChoice = 0, iValue = 0, iRet = 0;

    cout<<"-------------------------------------------------------------------\n";
    cout<<"----------------------------------Queue-----------------------------\n";
    cout<<"-------------------------------------------------------------------\n\n";

    while(1)
    {
        cout<<"-------------------------------------------------------------------\n";
        cout<<"----------------------Please Select the option----------------------\n";
        cout<<"-------------------------------------------------------------------\n";

        cout<<"1 : Insert new node in the Queue\n";
        cout<<"2 : Remove Element from the Queue\n";
        cout<<"3 : Display all elements from the Queue\n";
        cout<<"4 : Count all the elements from the Queue\n";
        cout<<"0 : Terminate the position\n";
        cout<<"-------------------------------------------------------------------\n";

        cin>>iChoice;

        if(iChoice == 1)
        {
            cout<<"Enter the data that you want to insert : \n";
            cin>>iValue;
            sobj.enqueue(iValue);
        }
        else if(iChoice == 2)
        {
            cout<<"Remove the element from the stack\n";
            iRet = sobj.dequeue();
            cout<<"Removed element from the Queue is : "<<iRet<<"\n";
        }
        else if(iChoice == 3)
        {
            sobj.Display();
        }
        else if(iChoice == 4)
        {
            iRet = sobj.Count();
            cout<<"The number of elements in the Queue are : "<<iRet<<"\n";
        }
        else if(iChoice == 0)
        {
            cout<<"Thank you for using our application\n";
            break;
        }
        else
        {
            cout<<"Invalid choice\n";
        }
        cout<<"\n-------------------------------------------------------------------\n";
    }

    return 0;
}