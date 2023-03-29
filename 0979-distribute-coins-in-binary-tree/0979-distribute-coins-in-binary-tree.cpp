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
    int dfs(TreeNode* root,int& res){
        if(root->left)
            root->val+=dfs(root->left,res);
        if(root->right)
            root->val+=dfs(root->right,res);
        int temp=root->val-1;
        res+=abs(temp);
        return temp;
    }
    int distributeCoins(TreeNode* root) {
        int res=0;
        dfs(root,res);
        return res;
    }
};
