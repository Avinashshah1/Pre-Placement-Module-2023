class Solution {
public:
    
    int rob_helper(vector<int>&nums,int n,bool flag,vector<vector<int>>&dp){
        
        if(n<0){
            return 0;
        }
        
        
        if(n==0 && flag && nums.size()>1){
            return 0;
        }
        
        if(dp[n][flag]!=-1){
            return dp[n][flag];
        }
        
        int inc=0,exc=0;
        
        inc=nums[n]+rob_helper(nums,n-2,flag,dp);
        
        if(n==nums.size()-1){
            flag=false;
        }
        
        exc=rob_helper(nums,n-1,flag,dp);
         
        return dp[n][flag] = max(inc,exc);
        
        
    }
    
    int rob(vector<int>& nums) {
        
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return rob_helper(nums,nums.size()-1,true,dp);
    }
};