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
    void dfs(TreeNode* root,vector<int>& num){
        if(root==NULL)  return;
        num.push_back(root->val);
        dfs(root->left,num);
        dfs(root->right,num);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> num;
        dfs(root,num);
        sort(num.begin(),num.end());
        int diff=INT_MAX;
        for(int i=1;i<num.size();i++){
            diff=min(diff,num[i]-num[i-1]);
        }
        return diff;
    }
};
