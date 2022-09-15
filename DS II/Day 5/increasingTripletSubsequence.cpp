class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n<3)
            return false;
        
        int one=INT_MAX,two=INT_MAX;
        
        for(auto i:nums)
        {
            if(one>i)
                one=i;
            else if(one<i && two>i)
                two=i;
            else if(two<i)
                return true;
        }
        
        return false;
        
    }
};