class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                dp[i]=1;
                res=max(res,dp[i]);
            }
            else{
                int mx=0;
                for(int j=0;j<i;j++){
                    if(nums[j]<nums[i] && mx<dp[j]){
                        mx=dp[j];
                    }
                }
                dp[i]=1 + mx;
                res=max(res,dp[i]);
            }
        }
        // for(int i=0;i<nums.size();i++)
        //     cout<<dp[i]<<" ";
        return res;
    }
};