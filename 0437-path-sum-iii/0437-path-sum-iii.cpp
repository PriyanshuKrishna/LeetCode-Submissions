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
private:
    void dfs(TreeNode* root,long long target,int& count){
        if(root==NULL)  return;
        if(root->val==target)
            count++;
        dfs(root->left,target-root->val,count);
        dfs(root->right,target-root->val,count);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        vector<vector<TreeNode*>> res;
        if(root==NULL) 
            return count;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*> temp;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();q.pop();
                temp.push_back(node);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(temp);
        }
        for(auto i:res){
            for(auto it:i)
                dfs(it,(long long)targetSum,count);
        }
        return count;
    }
};