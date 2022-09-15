class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        vector<int> res;
        res.push_back(firstOcc(nums,low,high,target));
        res.push_back(lastOcc(nums,low,high,target));
        return res;
    }
    
    int firstOcc(vector<int> &nums,int low,int high,int x){
        if(low>high)
            return -1;
        int mid=(low+high)/2;
        if(nums[mid]==x){
            if(mid==0)
                return mid;
            else if(nums[mid-1]==x)
               return firstOcc(nums,low,mid-1,x);
            else
                return mid;

        }
        else if(nums[mid]>x)
            return firstOcc(nums,low,mid-1,x);
        else
            return firstOcc(nums,mid+1,high,x);
    }
    
     int lastOcc(vector<int> &nums,int low,int high,int x){
        if(low>high)
            return -1;
        int mid=(low+high)/2;
        if(nums[mid]==x){
            if(mid==nums.size()-1)
                return mid;
            else if(nums[mid+1]==x)
               return lastOcc(nums,mid+1,high,x);
            else
                return mid;

        }
        else if(nums[mid]>x)
            return lastOcc(nums,low,mid-1,x);
        else
            return lastOcc(nums,mid+1,high,x);
    }
};