class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        lst=list()
        if(rowIndex==0):
            lst.append([1])
        elif(rowIndex==1):
            lst.append([1])
            lst.append([1,1])
        elif(rowIndex==2):
            lst.append([1])
            lst.append([1,1])
            lst.append([1,2,1])
        else:
            lst.append([1])
            lst.append([1,1])
            lst.append([1,2,1])
            for j in range(3,rowIndex+1):
                    lst3=lst[len(lst)-1]
                    lst2=[1]
                    for i in range(0,len(lst)-1):
                         lst2.append(lst3[i]+lst3[i+1])
                    lst2.append(1)
                    lst.append(lst2)        
        return lst[len(lst)-1]