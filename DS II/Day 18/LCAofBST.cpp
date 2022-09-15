/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        if(root->val==p->val || root->val==q->val)
            return root;
        TreeNode *lca1=lowestCommonAncestor(root->left,p,q);
        TreeNode *lca2=lowestCommonAncestor(root->right,p,q);
        if(lca1!=nullptr && lca2!=nullptr)
            return root;
        // if(lca1!=nullptr && lca2==nullptr)
        //     return lca1;
        // else
        //     return lca2;
        if(lca1!=nullptr && lca2==nullptr)
            return lca1;
        if(lca1==nullptr && lca2!=nullptr)
            return lca2;
        else
            return nullptr;
        
    }
};