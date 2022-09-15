class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0,j=height.size()-1;
        int res=0;
        while(i<j){
            int m=min(height[i],height[j]);
            res=max(res,m*(j-i));
            if(m==height[i])
                i++;
            else
                j--;
        }
        return res;
    }
};