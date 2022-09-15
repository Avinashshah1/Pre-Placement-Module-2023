class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int sum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            sum=max(sum,currsum);
            if(currsum<0)
                currsum=0;
        }
        return sum;
    }
};