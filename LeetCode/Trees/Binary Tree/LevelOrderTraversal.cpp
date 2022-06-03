vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> ans;
        vector<int>pre;
        
         if(root==NULL){
            return ans;
        }
        
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            
            if(curr==NULL){
            ans.push_back(pre);
            pre.clear();
            
            if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                pre.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }