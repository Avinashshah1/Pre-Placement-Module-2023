class Solution {
public:
    void solve(vector<int> nums, vector<int> op, vector<vector<int>> &res)
     {
         if (nums.size() == 0)
         {
            res.push_back(op);
            return;
        }
        vector<int> op1(op);
        vector<int> op2(op);
        op2.push_back(nums[0]);
        nums.erase(nums.begin());
        solve(nums, op1, res);
        solve(nums, op2, res);
        }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<int> op;
            vector<vector<int>> res;
            solve(nums, op, res);
            set<vector<int>> r;
            for(auto a:res){
                sort(a.begin(),a.end());
                r.insert(a);
            }
            res.erase(res.begin(),res.end());
            for(auto a: r)
                res.push_back(a);
            return res;
    }
};