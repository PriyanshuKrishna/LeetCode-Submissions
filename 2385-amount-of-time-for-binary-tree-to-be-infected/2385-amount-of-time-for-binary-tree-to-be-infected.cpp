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
    int findMaxDistance(map<TreeNode*,TreeNode*>& mp,TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,int> vis;
        vis[target]=1;
        int maxi=0;
        while(!q.empty()){
            int n=q.size();
            int fl=0;
            for(int i=0;i<n;i++){
                auto node=q.front();q.pop();
                if(node->left && !vis[node->left]){
                    fl=1;
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl=1;
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mp.find(node)!=mp.end() && !vis[mp[node]]){
                    fl=1;
                    vis[mp[node]]=1;
                    q.push(mp[node]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
    TreeNode* bfs(TreeNode* root,map<TreeNode*,TreeNode*>& mp,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* rs;
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            if(node->val==start) 
                rs=node;
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return rs;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;
        TreeNode* target=bfs(root,mp,start);
        int maxi=findMaxDistance(mp,target);
        return maxi;
    }
};