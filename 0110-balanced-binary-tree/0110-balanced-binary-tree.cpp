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
    bool ans;
    int checkBalance(TreeNode* root){
        if(root==nullptr)   return 0;
        if(ans==false)      return 0;
        int lsubtree=checkBalance(root->left);
        int rsubtree=checkBalance(root->right);
        if(abs(lsubtree-rsubtree)>1)
            ans=false;
        return 1+max(lsubtree,rsubtree);
    }
public:
    bool isBalanced(TreeNode* root) {
        ans=true;
        int temp=checkBalance(root);
        return ans;
    }
};

