class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()];
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1)
                dp[i]=0;
            else if(nums[i]==0)
                dp[i]=INT_MAX-1;
            else{
                int mn=INT_MAX-1;
                int temp=nums[i];
                int j=i+1;
                while(temp>0 && j<nums.size()){
                    mn=min(mn,dp[j]);
                    temp--;
                    j++;
                }
                dp[i]=1 + mn;
            }
        }
        for(int i=0;i<nums.size();i++)
            cout<<dp[i]<<" ";
        return dp[0];
    }
};