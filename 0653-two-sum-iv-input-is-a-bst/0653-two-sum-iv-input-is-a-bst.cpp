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
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,root,k);
    }
    bool dfs(TreeNode* root,TreeNode* curr,int k){
        if(curr==NULL) return false;
        return search(root,curr,k-curr->val) || dfs(root,curr->left,k) || dfs(root,curr->right,k);
    }
    bool search(TreeNode* root,TreeNode* curr,int value){
        if(root==NULL) return false;
        return (root->val==value) && (root!=curr) 
                || (root->val<value) && search(root->right,curr,value) 
                || (root->val>value) && search(root->left,curr,value);
    }
};

