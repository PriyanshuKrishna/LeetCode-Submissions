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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL,NULL);
    }
    bool isValidBST(TreeNode* root,TreeNode* minval,TreeNode* maxval){
        if(root==NULL)  return true;
        if((minval && root->val<=minval->val) ||(maxval && root->val>=maxval->val))  return false;
        return isValidBST(root->left,minval,root) && isValidBST(root->right,root,maxval);
    }
};