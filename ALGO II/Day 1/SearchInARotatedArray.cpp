class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        if(nums.size()>1){
            if(nums[1]==target)
                return 1;
        }
        if(nums.size()>4){
            if(nums[4]==target)
                return 4;
        }

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>nums[low]){
                if(target>=nums[low] && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                     high=mid-1;
            }
        }
        return -1;
    }
};