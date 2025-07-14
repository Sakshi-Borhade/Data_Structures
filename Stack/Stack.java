import java.util.Scanner;

class node
{
    public int data;
    public node next;
}

class StackX
{
    private node first;
    private int iCount;

    
    public StackX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    public int pop()
    {
        node temp = first;

        if(this.first == null)
        {
            System.out.println("Unable to pop as stack is empty");
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
            System.out.println("| "+temp.data+" |");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class Stack
{
    public static void main(String A[])
    {
        StackX sobj = new StackX();
        Scanner sobj1 = new Scanner(System.in);
        int iRet = 0, iValue = 0, iChoice = 0;

        System.out.print("-------------------------------------------------------------------\n");
        System.out.print("---------------------------------Stack------------------------------\n");
        System.out.print("-------------------------------------------------------------------\n\n");

        while(true)
        {
            System.out.print("-------------------------------------------------------------------\n");
            System.out.print("----------------------Please Select the option----------------------\n");
            System.out.print("-------------------------------------------------------------------\n");

            System.out.print("1 : Insert new node in the stack\n");
            System.out.print("2 : Pop Element from the stack\n");
            System.out.print("3 : Display all elements from the Stack\n");
            System.out.print("4 : Count all the elements from the stack\n");
            System.out.print("0 : Terminate the position\n");
            System.out.print("-------------------------------------------------------------------\n");

            iChoice = sobj1.nextInt();

            if(iChoice == 1)
            {
                System.out.print("Enter the data that you want to insert : \n");
                iValue = sobj1.nextInt();
                sobj.push(iValue);
            }
            else if(iChoice == 2)
            {
                System.out.print("Remove the element from the stack\n");
                iRet = sobj.pop();
                System.out.println("Removed element from the stack is : \n"+iRet);
            }
            else if(iChoice == 3)
            {
                sobj.Display();
            }
            else if(iChoice == 4)
            {
                iRet = sobj.Count();
                System.out.print("The number of elements in the stack are : "+iRet);
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