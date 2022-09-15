class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int x=arr[0];
        int maxprofit=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-x>maxprofit)
              maxprofit=arr[i]-x;
            if(arr[i]<x)
              x=arr[i];
        }
        return maxprofit;
    }
};