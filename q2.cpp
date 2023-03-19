class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;// make queue for nodes;
        
        if(root == NULL)
            return ans;
    
    q.push(root); //else push root into queue
    int f=0;

    while(q.size()){ //run while loop till the size of queue
        vector<int>temp; //where we will push all values into ans;
        int size = q.size(); //current size of queue
        
        while(size--){  // run loop until si becomes zero
            TreeNode* te =q.front(); // put all the front value in queue in te
            q.pop(); // queue is now empty
            if(te-> left != NULL)
                q.push(te->left); //push left value of root in the queue;
            if(te->right != NULL)
                q.push(te->right);
            temp.push_back(te->val); //push the value of root in temp vector; 
        }

        if(f == 0){
            f = 1; // update value of f
            ans.push_back(temp); // push back it into ans;
        }
        else{
             reverse(temp.begin(), temp.end());
             ans.push_back(temp);
             f=0; // update it again to 0 for next level or state;
        }
    }
    return ans;
}

};
