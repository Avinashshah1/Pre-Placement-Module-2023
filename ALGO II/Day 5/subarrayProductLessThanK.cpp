class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int pdt=1;
        int left=0,right=0;
        while(right<=nums.size()-1){
            
            pdt*=nums[right];
            while(pdt>=k and left<nums.size()){
                pdt/=nums[left];
                left++;
                
            }
            if(right-left>=0)
            ans+=right-left+1;
            right++;
            
        }
        return ans;
    }
};