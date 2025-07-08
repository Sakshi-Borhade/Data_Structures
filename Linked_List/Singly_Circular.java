import java.util.Scanner;

class node
{
    public int data;
    public node next;
}

class SinglyCLL
{
    private node first;
    private node last;
    private int iCount;
    
    public SinglyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        
        newn = new node();

        newn.data = no;
        newn.next = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;

            last.next = first;
        }

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
            last.next = first;
        }
        iCount++;
    }

    public void Display()
    {
        node temp = null;

        if((first == null) && (last == null))
        {
            System.out.println("Linked list is empty");
            return;
        }

        temp = first;

        do
        {
            System.out.print("| "+temp.data+" |-> ");
            temp = temp.next;

        }while(temp != last.next);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if((first == null) && (last == null))
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }

            last = temp;
            last.next = first;
        }
        iCount--;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        if((pos < 1) || (pos > iCount+1))
        {
            System.out.println("Invalid position");
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
            newn = new node();

            newn.data = no;
            newn.next = null;

            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }   
            
            newn.next = temp.next;
            temp.next = newn;
            
            iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if((pos < 1) || (pos > iCount))
        {
            System.out.println("Invalid position");
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
                temp = temp.next;
            }   
            
            temp.next = temp.next.next;
            
            iCount--;
        }
    }
}

class Singly_Circular
{
    public static void main(String A[])
    {
        SinglyCLL sobj = new SinglyCLL();
        Scanner sobj1 = new Scanner(System.in);
        int iRet = 0, iChoice = 0, iValue = 0, iPos = 0;

        System.out.print("-------------------------------------------------------------------\n");
        System.out.print("----------------------Singly Linear Linked List--------------------\n");
        System.out.print("-------------------------------------------------------------------\n\n");

        while(true)
        {
            System.out.print("-------------------------------------------------------------------\n");
            System.out.print("----------------------Please Select the option----------------------\n");
            System.out.print("-------------------------------------------------------------------\n");

            System.out.print("1 : Insert new node at first position\n");
            System.out.print("2 : Insert new node at last position\n");
            System.out.print("3 : Insert new node at given position\n");
            System.out.print("4 : Delete new node at first position\n");
            System.out.print("5 : Delete new node at last position\n");
            System.out.print("6 : Delete new node at given position\n");
            System.out.print("7 : Display all elements of Linked list\n");
            System.out.print("8 : Count number of nodes of linked list\n");
            System.out.print("0 : Terminate the application\n");
            System.out.print("-------------------------------------------------------------------\n");

            iChoice = sobj1.nextInt();

            if(iChoice == 1)
            {
                System.out.print("Enter the data that you want to insert : \n");
                iValue = sobj1.nextInt();
                sobj.InsertFirst(iValue);
            }
            else if(iChoice == 2)
            {
                System.out.print("Enter the data that you want to insert Last : \n");
                iValue = sobj1.nextInt();
                sobj.InsertLast(iValue);
            }
            else if(iChoice == 3)
            {
                System.out.print("Enter the data that you want to insert Last : \n");
                iValue = sobj1.nextInt();

                System.out.print("Enter the position at which you want to insert : \n");
                iPos = sobj1.nextInt();

                sobj.InsertAtPos(iValue,iPos);
            }
            else if(iChoice == 4)
            {
                System.out.print("Deleting the first element from the Linked List");

                sobj.DeleteFirst();
            }
            else if(iChoice == 5)
            {
                
                System.out.print("Deleting the last element from the Linked List");

                sobj.DeleteLast();
            }
            else if(iChoice == 6)
            {
                System.out.print("Deleting the element from the given position\n");

                System.out.print("Enter the position from which you want to delete : \n");
                iPos = sobj1.nextInt();

                sobj.DeleteAtPos(iPos);
            }
            else if(iChoice == 7)
            {
                System.out.print("Elements of the linked list are : \n");

                sobj.Display();
            }
            else if(iChoice == 8)
            {
                sobj.Display();
                iRet = sobj.Count();
                System.out.print("Number of elements in the linked list are : "+iRet);
            }
            else if(iChoice == 0)
            {
                System.out.print("Thank you for using our application\n");
                break;
            }
            else
            {
                System.out.print("Invalid choice\n");
            }
            System.out.print("\n-------------------------------------------------------------------\n");
        }    
    }
}
