class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        if(nums.size()==2){
            return max(dp[0],dp[1]);   
        }
        for(int i=2;i<nums.size();i++){
            int maxi=0;
            for(int j=0;j<=i-2;j++){
                maxi=max(maxi,dp[j]);
            }
            dp[i]=maxi+nums[i];
        }
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};