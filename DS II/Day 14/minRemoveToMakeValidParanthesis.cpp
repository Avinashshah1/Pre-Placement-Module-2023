class Solution {
public:
    int findTheWinner(int n, int k) {
       int circle[n];
       for(int i=0;i<n;i++)
            circle[i]=i+1;
       int i=0;
       while(n>1){
           int temp=k-1;
           while(temp>0){
               i=(i+1)%n;
               temp--;
           }
           n=deleteElement(circle,n,i);
           i=i%n;
       }
        return circle[0]; 
    }   
    
  int deleteElement(int arr[],int size ,int index)
   {
      for(int i=index;i<size-1;i++){
          arr[i]=arr[i+1];
      }
      size--;
      return size;
    }
};