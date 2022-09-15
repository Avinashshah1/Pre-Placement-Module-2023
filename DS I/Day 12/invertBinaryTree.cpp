class Solution {
public:
bool hasPathSum(TreeNode* root, int targetSum) {
if(root==NULL ) return false;
if(root->left==NULL and root->right==NULL) return (targetSum==root->val);
return hasPathSum(root->left,targetSum-root->val) or hasPathSum(root->right,targetSum-root->val);
}
};