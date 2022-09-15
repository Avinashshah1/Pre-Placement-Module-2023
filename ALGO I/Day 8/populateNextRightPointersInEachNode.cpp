class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        Node* n;
        queue<Node*> q;
        q.push(root);
        int c=q.size();
        while(!q.empty())
        {
            n=q.front();
            q.pop();
            c--;
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right);
            if(c==0)
            {
                n->next=NULL;
                c=q.size();
            }
            else
                n->next=q.front();
        }
        return root;
    }
};