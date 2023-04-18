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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* root=head;
        vector<int> tmp;
        while(root!=NULL){
            tmp.push_back(root->val);
            root=root->next;
        }
        int n=tmp.size();
        swap(tmp[k-1],tmp[n-k]);
        root=head;
        for(int i=0;i<n;i++){
            root->val=tmp[i];
            root=root->next;
        }
        return head;
    }
};