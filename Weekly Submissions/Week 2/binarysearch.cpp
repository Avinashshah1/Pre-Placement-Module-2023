int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums.at(mid)<target){
                low=mid+1;
            }
            else if(nums.at(mid)>target){
                high=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }