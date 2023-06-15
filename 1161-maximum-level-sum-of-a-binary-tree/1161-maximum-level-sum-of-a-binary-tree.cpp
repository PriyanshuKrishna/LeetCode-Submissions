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
    int maxLevelSum(TreeNode* root) {
        if(!root) 
            return 1;
        queue<TreeNode*> q;
        q.push(root);
        int level=0,maxi=INT_MIN,rs=0;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            ++level;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();   q.pop();
                if(node->left!=NULL)    q.push(node->left);
                if(node->right!=NULL)   q.push(node->right);
                sum+=node->val;
            }
            if(maxi<sum){
                maxi=sum;
                rs=level;
            }
        }
        return rs;
    }
};