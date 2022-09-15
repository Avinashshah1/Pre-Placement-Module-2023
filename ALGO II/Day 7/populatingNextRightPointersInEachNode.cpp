class Solution {
public:
      Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
         
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
       
          while(q.empty()==false){
             
              while(q.front()!=NULL){
                  Node* front = q.front();
                  if(front->left){
                      q.push(front->left);
                  }
                  if(front->right){
                      q.push(front->right);
                  }
               
                  q.pop(); 
				
                  front->next = q.front();
              }
			  
              q.pop();
              if(q.size()>=1){
                  q.push(NULL);
              }
          }
            
       
        return root;
    }
};