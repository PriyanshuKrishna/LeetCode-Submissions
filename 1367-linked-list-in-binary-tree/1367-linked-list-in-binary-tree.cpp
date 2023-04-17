/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(ListNode* h,TreeNode* r){
        if(h==NULL)
            return true;
        if(r==NULL)
            return false;
        return (h->val==r->val) && (check(h->next,r->left) || check(h->next,r->right));
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) 
            return false;
        return check(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};