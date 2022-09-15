class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        lst=list()
        if(numRows==1):
            lst.append([1])
        elif(numRows==2):
            lst.append([1])
            lst.append([1,1])
        elif(numRows==3):
            lst.append([1])
            lst.append([1,1])
            lst.append([1,2,1])
        else:
            lst.append([1])
            lst.append([1,1])
            lst.append([1,2,1])
            for j in range(4,numRows+1):
                    lst3=lst[len(lst)-1]
                    lst2=[1]
                    for i in range(0,len(lst)-1):
                         lst2.append(lst3[i]+lst3[i+1])
                    lst2.append(1)
                    lst.append(lst2)        
        return lst
                    
                
            
            