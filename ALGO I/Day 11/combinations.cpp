class Solution {
public:    
    void helper(int n, int k, int idx, vector<int>& interM, vector<vector<int>>& outputs){
        if(interM.size()==k){
            outputs.push_back(interM);
            return;
        }
        for(int i = idx; i<=n;i++){
            interM.push_back(i);
            helper(n, k, i+1, interM, outputs);
            interM.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> outputs;
        int idx = 1;
        vector<int> intermediateOutputs;
        helper(n,k,idx,intermediateOutputs, outputs);
        return outputs;
    }
};