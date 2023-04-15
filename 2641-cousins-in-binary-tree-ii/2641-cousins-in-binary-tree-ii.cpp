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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> mp;
        mp[0]=root->val;
        while(!q.empty()){
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();q.pop();
                if(node->left){
                    q.push(node->left);
                    mp[level]+=node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    mp[level]+=node->right->val;
                }
            }
        }
        level=0;
        q.push(root);
        root->val=0;
        while(!q.empty()){
            level++;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();q.pop();
                int left=node->left?(node->left->val):0;
                int right=node->right?(node->right->val):0;
                if(node->left){
                    q.push(node->left);
                    node->left->val=mp[level]-left-right;
                }
                if(node->right){
                    q.push(node->right);
                    node->right->val=mp[level]-left-right;
                }
            }
        }
        return root;
    }
};