import java.util.Scanner;

class node
{
    public int data;
    public node next;
}

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void enqueue(int no)             
    {
        node temp = null;
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
        iCount++;
    }

    public int dequeue()           
    {
        node temp = first;

        if(this.first == null)
        {
            System.out.println("Unable to remove as Queue is empty");
            return -1;
        }
        else
        {
            first = first.next;
            iCount--;
            return temp.data;
        }
    }

    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(temp != null)
        {
            System.out.println("| "+temp.data+" | - ");
            temp = temp.next;
        }
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class Queue
{
    public static void main(String A[])
    {
        QueueX sobj = new QueueX();
        Scanner sobj1 = new Scanner(System.in);
        int iRet = 0, iValue = 0, iChoice = 0;

        System.out.print("-------------------------------------------------------------------\n");
        System.out.print("---------------------------------Queue------------------------------\n");
        System.out.print("-------------------------------------------------------------------\n\n");

        while(true)
        {
            System.out.print("-------------------------------------------------------------------\n");
            System.out.print("----------------------Please Select the option----------------------\n");
            System.out.print("-------------------------------------------------------------------\n");

            System.out.print("1 : Insert new node in the Queue\n");
            System.out.print("2 : Remove Element from the Queue\n");
            System.out.print("3 : Display all elements from the Queue\n");
            System.out.print("4 : Count all the elements from the Queue\n");
            System.out.print("0 : Terminate the position\n");
            System.out.print("-------------------------------------------------------------------\n");

            iChoice = sobj1.nextInt();

            if(iChoice == 1)
            {
                System.out.print("Enter the data that you want to insert : \n");
                iValue = sobj1.nextInt();
                sobj.enqueue(iValue);
            }
            else if(iChoice == 2)
            {
                System.out.print("Remove the element from the stack\n");
                iRet = sobj.dequeue();
                System.out.println("Removed element from the Queue is : \n"+iRet);
            }
            else if(iChoice == 3)
            {
                sobj.Display();
            }
            else if(iChoice == 4)
            {
                iRet = sobj.Count();
                System.out.print("The number of elements in the Queue are : "+iRet);
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