class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        
        int rp=1;
        
        for(int i=0;i<nums.size();i++){
            result[i]=rp;
            rp=rp*nums[i];
        }
        
        rp=1;
        for(int i=nums.size()-1;i>=0;i--){
            result[i]=result[i]*rp;
            rp=rp*nums[i];
        }
        return result;
    }
};