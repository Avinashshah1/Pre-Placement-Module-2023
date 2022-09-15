class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[nums.size()];
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1)
                dp[i]=true;
            else if(nums[i]==0)
                dp[i]=false;
            else{
                int flag=false;
                int temp=nums[i];
                int j=i+1;
                while(temp>0 && j<nums.size()){
                    if(dp[j]==true)
                        flag=true;
                    temp--;
                    j++;
                }
                dp[i]=flag;
            }
        }
        // for(int i=0;i<nums.size();i++)
        //     cout<<dp[i]<<" ";
        return dp[0];
    }
};