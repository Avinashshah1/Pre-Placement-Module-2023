class Solution {
private:
    vector<int>intersect(vector<int>&f,vector<int>&s){
        return {max(f[0],s[0]),min(f[1],s[1])};
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        vector<int>starts,ends;
        for(vector<int>second:secondList){
            starts.push_back(second[0]);
            ends.push_back(second[1]);
        }
        for(vector<int>first:firstList){
            int begin=lower_bound(ends.begin(),ends.end(),first[0])-ends.begin();
            int end=upper_bound(starts.begin(),starts.end(),first[1])-starts.begin();
            for(int i=begin;i<end;i++){
                ans.push_back(intersect(first,secondList[i]));
            }
        }
        return ans;
    }
};