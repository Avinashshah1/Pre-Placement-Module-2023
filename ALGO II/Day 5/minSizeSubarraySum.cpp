class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        auto valid = [&nums,&target](int l) {
            int i = 0, j = l, sum = accumulate(nums.begin(),nums.begin()+l,0), n = nums.size();
            if(sum >= target) return true;
            while(j < n) {
                sum -= nums[i++];
                sum += nums[j++];
                if(sum >= target) return true;
            }
            
            return false;
        };
        
        int l = 1, r = nums.size(), ans = 0;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(valid(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        
        return ans;
    }
};