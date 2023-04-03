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
    void solve(TreeNode* root,string s,vector<string>& ans){
        if(root->left==NULL && root->right==NULL)
            ans.push_back((char)(root->val+'a')+s);
        if(root->left!=NULL)
            solve(root->left,(char)(root->val+'a')+s,ans);
        if(root->right!=NULL)
            solve(root->right,(char)(root->val+'a')+s,ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        vector<string> ans;
        solve(root,s,ans);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};

