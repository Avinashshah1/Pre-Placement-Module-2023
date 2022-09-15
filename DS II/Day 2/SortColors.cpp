class Solution {
public:
    void sortColors(vector<int>& nums) {
       countSort(nums);
    }
    
    void countSort(vector<int>& nums){
        int m=findMax(nums);
        int C[m+1];
        for(int i=0;i<m+1;i++)
            C[i]=0;
        
        for(int i=0;i<nums.size();i++)
            C[nums[i]]++;
        
        int i=0,j=0;
        while(i<m+1){
            if(C[i]>0){
                nums[j++]=i;
                C[i]--;
            }
            else
                i++;
        }           
    }
    
    int findMax(vector<int>& nums){
        int max=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
                max=nums[i];
        }
        return max;
        }
};
