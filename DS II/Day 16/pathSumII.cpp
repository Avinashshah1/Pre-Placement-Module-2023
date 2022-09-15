vector<vector<int>> ans;
    void pathSum2(TreeNode* root, vector<int>& path, int target) {
        
        if(root == NULL) return;
        
        path.push_back(root->val);
        
        if(root->left == NULL and root->right == NULL and target == root->val) {
            ans.push_back(path);
        }
       
        pathSum2(root->left, path, target-root->val);
        pathSum2(root->right, path, target-root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pathSum2(root, path, targetSum);
        return ans;
    }