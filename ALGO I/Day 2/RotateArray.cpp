class Solution {
public:
    void reverse(vector<int> &nums,int i,int j){
        int li=i;
        int ri=j;
        while(li<ri){
           int temp=nums[li];
            nums[li]=nums[ri];
            nums[ri]=temp;
            li++;
            ri--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
         k=k%n;
        if(k<0){
          k=k+n;
        }
        
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        for(int i=0;i<n;i++){
            cout<<nums[i];
        }
    }
    
};