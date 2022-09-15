int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(auto &val: nums)
        {
            sum=sum+val;
            ans=ans+mp[sum-k];
            mp[sum]++;
            
        }
        return ans;
    }