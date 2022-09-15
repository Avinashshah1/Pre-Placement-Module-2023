class BSTIterator {
private: 
    int index;
    vector<int> inOrderPath;
    void makeInOrder(vector<int>& path, TreeNode* node) {
        if(node!=nullptr) {
            makeInOrder(path, node->left);
            inOrderPath.push_back(node->val);
            makeInOrder(path, node->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        makeInOrder(this->inOrderPath, root);
        index = 0;
    }
    
    int next() {
        return this->inOrderPath[index++];
    }
    
    bool hasNext() {
        return index<inOrderPath.size();
    }
};
