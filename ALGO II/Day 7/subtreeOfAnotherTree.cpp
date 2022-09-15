/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    queue<TreeNode*> t1;
    queue<TreeNode*> t2;
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (node1) t1.push(node1);
        if (node2) t2.push(node2);
        while(!(t1.empty() && t2.empty())) {
            
            node1 = t1.front();
            node2 = t2.front();
            t1.pop();
            t2.pop();
            if (node1->val != node2->val) return false;
            
            if (node1->left && node2->left) {
                t1.push(node1->left);
                t2.push(node2->left);
            } else if (node1->left || node2->left){
                return false;
            }
            
            if (node1->right && node2->right) {
                t1.push(node1->right);
                t2.push(node2->right);
            } else if(node1->right || node2->right) {
                return false;
            }
        }
        return t1.empty() && t2.empty() ? true : false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> t;
        
        t.push(root);
        
        while(!t.empty()) {
            root = t.front();
            t.pop();
            if (root->val == subRoot->val) {
                if (isSameTree(root, subRoot)) return true;
                while(!t1.empty()) {
                    t1.pop();
                    if (!t2.empty()) {
                        t2.pop();
                    }
                }
                while(!t2.empty()){
                    t2.pop();
                }
            }
            
            if (root->left) t.push(root->left);
            if (root->right) t.push(root->right);
        }
        return false;
    }
};