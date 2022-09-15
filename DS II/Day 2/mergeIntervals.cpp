class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0) return ans;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> ds = intervals[0];
        
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0] <= ds[1]){
                ds[1] = max(ds[1], intervals[i][1]);
            }else{
                ans.push_back(ds);
                ds[0] = intervals[i][0];
                ds[1] = intervals[i][1];
            }
        }
        ans.push_back(ds);
        return ans;
    }
};