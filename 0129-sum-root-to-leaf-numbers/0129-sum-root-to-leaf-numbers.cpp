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
    int dfs(TreeNode* node,int total){
        if(!node)  
            return 0;
        
        total=total*10+node->val;
        
        if(!node->left && !node->right)
            return total;
        
        return dfs(node->left,total)+dfs(node->right,total);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};