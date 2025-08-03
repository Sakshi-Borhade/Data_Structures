class Node:
    
    def __init__(self,no):
        self.data = no
        self.next = None

class SinglyLLL:

    def __init__(self):
        self.first = None
        self.iCount = 0

########################################
    def InsertFirst(no):
        newn = Node(no)

        if(self.first == None):      
            self.first = newn
        else:                  
            newn.next = self.first
            self.first = newn

        self.iCount = self.iCount + 1

########################################
    def Display(self):

        temp = self.first

        while(temp != None):
            print(f"| {temp.data} |-> ",end = "")
            temp = temp.next
        print("None")

########################################
    def Count(self):
        return self. iCount

########################################
    def InsertLast(self,no):
        newn = Node(no)

        if(self.first == None):      
            self.first = newn
        
        else:                    
            
            temp = self.first

            while(temp.next != None):
                temp = temp.next

            temp.next = newn

        self.iCount = self.iCount + 1
########################################
    def DeleteFirst(self):
            
        if(self.first == None):
            return
        else:

            temp = self.first
            self.first = self.first.next
            del temp

        self.iCount = self.iCount - 1

########################################

    def DeleteLast(self):
        
        if(self.first == None):   
            return

        elif(self.first.next == None):    
            del self.first
            self.first = None

        else:                     
            temp = self.first

            while(temp.next.next != None):
                temp = temp.next

            del temp.next
            temp.next = None

        self.iCount = self.iCount - 1

########################################

    def InsertAtPos(self,no,pos):

        if(pos < 1 or pos > self.iCount+1): 
            print("Invalid position")
            return

        if(pos == 1):
            self.InsertFirst(no)
        elif(pos == self.iCount+1):
            self.InsertLast(no)
        else:

            newn = Node(no)

            temp = self.first

            for i in range(1,pos-1,1):
                temp = temp.next

            newn.next = temp.next
            temp.next = newn

        self.iCount = self.iCount + 1

########################################

    def DeleteAtPos(self,pos):

        if(pos < 1 or pos > self.iCount): 
            print("Invalid position")
            return

        if(pos == 1):
            self.DeleteFirst()
        elif(pos == self.iCount):
            self.InsertLast()
        else:

            temp = self.first

            for i in range(1,pos-1,1):
                temp = temp.next

            target = temp.next
            temp.next = target.next
            del target

        self.iCount = self.iCount - 1

########################################

def main():
    
    dobj = SinglyLLL()
    
    dobj.InsertFirst(51)
    dobj.InsertFirst(21)
    dobj.InsertFirst(11)

    dobj.InsertLast(101)
    dobj.InsertLast(111)
    dobj.InsertLast(121)

    dobj.Display()
    iRet = dobj.Count()
    print(f"The number of elements in the Linked list are : {iRet}")

    dobj.DeleteFirst()    
    dobj.Display()
    iRet = dobj.Count()
    print(f"The number of elements in the Linked list are : {iRet}")

    dobj.DeleteLast()
    dobj.Display()
    iRet = dobj.Count()
    print(f"The number of elements in the Linked list are : {iRet}")

    dobj.InsertAtPos(105,5)
    dobj.Display()
    iRet = dobj.Count()
    print(f"The number of elements in the Linked list are : {iRet}")
    
    dobj.DeleteAtPos(5)
    dobj.Display()
    iRet = dobj.Count()
    print(f"The number of elements in the Linked list are : {iRet}")


if __name__ == "__main__":
    main()