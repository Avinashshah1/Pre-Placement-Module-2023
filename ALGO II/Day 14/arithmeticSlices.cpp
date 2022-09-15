class Solution {
public:
    long long int numberOfArithmeticSlices(vector<int>& nums) {
        int dp[nums.size()];
        if(nums.size()<3)
            return 0;
        dp[0]=0;
        dp[1]=0;
        long long int sum=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                dp[i]=1 + dp[i-1];
            else
                dp[i]=0;
            sum+=dp[i];
        }
        return sum;
    }
};