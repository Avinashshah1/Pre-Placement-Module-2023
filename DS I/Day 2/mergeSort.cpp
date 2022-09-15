class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> merged(m+n);
        while(i!=m && j!=n){
            if(nums1[i]<nums2[j])
                merged[k++]=nums1[i++];
            else if(nums1[i]>=nums2[j])
                merged[k++]=nums2[j++];
        }
        for(;i<m;)
            merged[k++]=nums1[i++];
        for(;j<n;)
            merged[k++]=nums2[j++];
        nums1=merged;
    }
};