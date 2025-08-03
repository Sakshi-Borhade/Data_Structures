class Node:
    
    def __init__(self,no):
        self.data = no
        self.next = None
        self.prev = None

class DoublyCLL:

    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

########################################
    def InsertFirst(self,no):
        newn = Node(no)

        if(self.first == None):      
            self.first = newn
        else:                  
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

            self.last.next = self.first
            self.first.prev = self.last

        self.iCount = self.iCount + 1

########################################
    def Display(self):

        temp = self.first

        while True:
            print(f"| {temp.data} |<=> ",end = "")
            temp = temp.next

            if temp == self.first:
                break
        print()

########################################
    def Count(self):
        return self. iCount

########################################
    def InsertLast(self,no):
        newn = Node(no)

        if(self.first == None):      
            self.first = newn
        
        else:                    
            
            self.last.next = newn
            newn.prev = self.last
            self.last = newn
            self.last.next = self.first
            self.first.prev = self.last

        self.iCount = self.iCount + 1
########################################
    def DeleteFirst(self):
            
        if(self.first == None):
            return
        else:

            temp = self.first
            self.first = self.first.next
            del temp
            self.first.prev = self.last
            self.last.next = self.first

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
            temp.next = self.last

            self.last.next = self.first
            self.first.prev = self.last

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
            newn.next.prev = newn
            temp.next = newn
            newn.prev = temp

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
            target.next.prev = temp
            del target

        self.iCount = self.iCount - 1

########################################

def main():
    dobj = DoublyCLL()
    
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